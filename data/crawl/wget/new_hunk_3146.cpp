#define HTTP_STATUS_BAD_GATEWAY		502
#define HTTP_STATUS_UNAVAILABLE		503

static const char *
head_terminator (const char *hunk, int oldlen, int peeklen)
{
  const char *start, *end;

  /* If at first peek, verify whether HUNK starts with "HTTP".  If
     not, this is a HTTP/0.9 request and we must bail out without
     reading anything.  */
  if (oldlen == 0 && 0 != memcmp (hunk, "HTTP", MIN (peeklen, 4)))
    return hunk;

  if (oldlen < 4)
    start = hunk;
  else
    start = hunk + oldlen - 4;
  end = hunk + oldlen + peeklen;

  for (; start < end - 1; start++)
    if (*start == '\n')
      {
	if (start < end - 2
	    && start[1] == '\r'
	    && start[2] == '\n')
	  return start + 3;
	if (start[1] == '\n')
	  return start + 2;
      }
  return NULL;
}

/* Read the HTTP request head from FD and return it.  The error
   conditions are the same as with fd_read_hunk.

   To support HTTP/0.9 responses, this function tries to make sure
   that the data begins with "HTTP".  If this is not the case, no data
   is read and an empty request is returned, so that the remaining
   data can be treated as body.  */

static char *
fd_read_http_head (int fd)
{
  return fd_read_hunk (fd, head_terminator, 512);
}

struct response {
  /* The response data. */
  const char *data;

  /* The array of pointers that indicate where each header starts.
     For example, given three headers "foo", "bar", and "baz":
       foo: value\r\nbar: value\r\nbaz: value\r\n\r\n
       0             1             2             3
     I.e. headers[0] points to the beginning of foo, headers[1] points
     to the end of foo and the beginning of bar, etc.  */
  const char **headers;
};

static struct response *
response_new (const char *head)
{
  const char *hdr;
  int count, size;

  struct response *resp = xnew0 (struct response);
  resp->data = head;

  if (*head == '\0')
    {
      /* Empty head means that we're dealing with a headerless
	 (HTTP/0.9) response.  In that case, don't set HEADERS at
	 all.  */
      return resp;
    }

  /* Split HEAD into header lines, so that response_header_* functions
     don't need to do this over and over again.  */

  size = count = 0;
  hdr = head;
  while (1)
    {
      DO_REALLOC (resp->headers, size, count + 1, const char *);
      resp->headers[count++] = hdr;

      /* Break upon encountering an empty line. */
      if (!hdr[0] || (hdr[0] == '\r' && hdr[1] == '\n') || hdr[0] == '\n')
	break;

      /* Find the end of HDR, including continuations. */
      do
	{
	  const char *end = strchr (hdr, '\n');
	  if (end)
	    hdr = end + 1;
	  else
	    hdr += strlen (hdr);
	}
      while (*hdr == ' ' || *hdr == '\t');
    }
  DO_REALLOC (resp->headers, size, count + 1, const char *);
  resp->headers[count++] = NULL;

  return resp;
}

static int
response_header_bounds (const struct response *resp, const char *name,
			const char **begptr, const char **endptr)
{
  int i;
  const char **headers = resp->headers;
  int name_len;

  if (!headers || !headers[1])
    return 0;

  name_len = strlen (name);

  for (i = 1; headers[i + 1]; i++)
    {
      const char *b = headers[i];
      const char *e = headers[i + 1];
      if (e - b > name_len
	  && b[name_len] == ':'
	  && 0 == strncasecmp (b, name, name_len))
	{
	  b += name_len + 1;
	  while (b < e && ISSPACE (*b))
	    ++b;
	  while (b < e && ISSPACE (e[-1]))
	    --e;
	  *begptr = b;
	  *endptr = e;
	  return 1;
	}
    }
  return 0;
}

static int
response_header_copy (const struct response *resp, const char *name,
		      char *buf, int bufsize)
{
  const char *b, *e;
  if (!response_header_bounds (resp, name, &b, &e))
    return 0;
  if (bufsize)
    {
      int len = MIN (e - b, bufsize);
      strncpy (buf, b, len);
      buf[len] = '\0';
    }
  return 1;
}

static char *
response_header_strdup (const struct response *resp, const char *name)
{
  const char *b, *e;
  if (!response_header_bounds (resp, name, &b, &e))
    return NULL;
  return strdupdelim (b, e);
}

/* Parse the HTTP status line, which is of format:

   HTTP-Version SP Status-Code SP Reason-Phrase

   The function returns the status-code, or -1 if the status line
   appears malformed.  The pointer to "reason-phrase" message is
   returned in *MESSAGE.  */

static int
response_status (const struct response *resp, char **message)
{
  int status;
  const char *p, *end;

  if (!resp->headers)
    {
      /* For a HTTP/0.9 response, always assume 200 response. */
      if (message)
	*message = xstrdup ("OK");
      return 200;
    }

  p = resp->headers[0];
  end = resp->headers[1];

  if (!end)
    return -1;

  /* "HTTP" */
  if (end - p < 4 || 0 != strncmp (p, "HTTP", 4))
    return -1;
  p += 4;

  /* "/x.x" (optional because some Gnutella servers have been reported
     as not sending the "/x.x" part.  */
  if (p < end && *p == '/')
    {
      ++p;
      while (p < end && ISDIGIT (*p))
	++p;
      if (p < end && *p == '.')
	++p; 
      while (p < end && ISDIGIT (*p))
	++p;
    }

  while (p < end && ISSPACE (*p))
    ++p;
  if (end - p < 3 || !ISDIGIT (p[0]) || !ISDIGIT (p[1]) || !ISDIGIT (p[2]))
    return -1;

  status = 100 * (p[0] - '0') + 10 * (p[1] - '0') + (p[2] - '0');
  p += 3;

  if (message)
    {
      while (p < end && ISSPACE (*p))
	++p;
      while (p < end && ISSPACE (end[-1]))
	--end;
      *message = strdupdelim (p, end);
    }

  return status;
}

static void
response_free (struct response *resp)
{
  xfree_null (resp->headers);
  xfree (resp);
}

static void
print_server_response_1 (const char *b, const char *e)
{
  char *ln;
  if (b < e && e[-1] == '\n')
    --e;
  if (b < e && e[-1] == '\r')
    --e;
  BOUNDED_TO_ALLOCA (b, e, ln);
  logprintf (LOG_VERBOSE, "  %s\n", ln);
}

static void
print_server_response (const struct response *resp)
{
  int i;
  if (!resp->headers)
    return;
  for (i = 0; resp->headers[i + 1]; i++)
    print_server_response_1 (resp->headers[i], resp->headers[i + 1]);
}

/* Parse the `Content-Range' header and extract the information it
   contains.  Returns 1 if successful, -1 otherwise.  */
static int
parse_content_range (const char *hdr, long *first_byte_ptr,
		     long *last_byte_ptr, long *entity_length_ptr)
{
  long num;

  /* Ancient versions of Netscape proxy server, presumably predating
     rfc2068, sent out `Content-Range' without the "bytes"
     specifier.  */
  if (!strncasecmp (hdr, "bytes", 5))
    {
      hdr += 5;
