#define HTTP_STATUS_BAD_GATEWAY		502
#define HTTP_STATUS_UNAVAILABLE		503


/* Parse the HTTP status line, which is of format:

   HTTP-Version SP Status-Code SP Reason-Phrase

   The function returns the status-code, or -1 if the status line is
   malformed.  The pointer to reason-phrase is returned in RP.  */
static int
parse_http_status_line (const char *line, const char **reason_phrase_ptr)
{
  /* (the variables must not be named `major' and `minor', because
     that breaks compilation with SunOS4 cc.)  */
  int mjr, mnr, statcode;
  const char *p;

  *reason_phrase_ptr = NULL;

  /* The standard format of HTTP-Version is: `HTTP/X.Y', where X is
     major version, and Y is minor version.  */
  if (strncmp (line, "HTTP/", 5) != 0)
    return -1;
  line += 5;

  /* Calculate major HTTP version.  */
  p = line;
  for (mjr = 0; ISDIGIT (*line); line++)
    mjr = 10 * mjr + (*line - '0');
  if (*line != '.' || p == line)
    return -1;
  ++line;

  /* Calculate minor HTTP version.  */
  p = line;
  for (mnr = 0; ISDIGIT (*line); line++)
    mnr = 10 * mnr + (*line - '0');
  if (*line != ' ' || p == line)
    return -1;
  /* Wget will accept only 1.0 and higher HTTP-versions.  The value of
     minor version can be safely ignored.  */
  if (mjr < 1)
    return -1;
  ++line;

  /* Calculate status code.  */
  if (!(ISDIGIT (*line) && ISDIGIT (line[1]) && ISDIGIT (line[2])))
    return -1;
  statcode = 100 * (*line - '0') + 10 * (line[1] - '0') + (line[2] - '0');

  /* Set up the reason phrase pointer.  */
  line += 3;
  /* RFC2068 requires SPC here, but we allow the string to finish
     here, in case no reason-phrase is present.  */
  if (*line != ' ')
    {
      if (!*line)
	*reason_phrase_ptr = line;
      else
	return -1;
    }
  else
    *reason_phrase_ptr = line + 1;

  return statcode;
}

#define WMIN(x, y) ((x) > (y) ? (y) : (x))

/* Send the contents of FILE_NAME to SOCK/SSL.  Make sure that exactly
   PROMISED_SIZE bytes are sent over the wire -- if the file is
   longer, read only that much; if the file is shorter, report an error.  */

static int
post_file (int sock, const char *file_name, long promised_size)
{
  static char chunk[8192];
  long written = 0;
  int write_error;
  FILE *fp;

  DEBUGP (("[writing POST file %s ... ", file_name));

  fp = fopen (file_name, "rb");
  if (!fp)
    return -1;
  while (!feof (fp) && written < promised_size)
    {
      int towrite;
      int length = fread (chunk, 1, sizeof (chunk), fp);
      if (length == 0)
	break;
      towrite = WMIN (promised_size - written, length);
      write_error = fd_write (sock, chunk, towrite, -1);
      if (write_error < 0)
	{
	  fclose (fp);
	  return -1;
	}
      written += towrite;
    }
  fclose (fp);

  /* If we've written less than was promised, report a (probably
     nonsensical) error rather than break the promise.  */
  if (written < promised_size)
    {
      errno = EINVAL;
      return -1;
    }

  assert (written == promised_size);
  DEBUGP (("done]\n"));
  return 0;
}

static const char *
next_header (const char *h)
{
  const char *end = NULL;
  const char *p = h;
  do
    {
      p = strchr (p, '\n');
      if (!p)
	return end;
      end = ++p;
    }
  while (*p == ' ' || *p == '\t');

  return end;
}

/* Skip LWS (linear white space), if present.  Returns number of
   characters to skip.  */
static int
skip_lws (const char *string)
{
  const char *p = string;

  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
    ++p;
  return p - string;
}

/* Check whether HEADER begins with NAME and, if yes, skip the `:' and
   the whitespace, and call PROCFUN with the arguments of HEADER's
   contents (after the `:' and space) and ARG.  Otherwise, return 0.  */
int
header_process (const char *header, const char *name,
		int (*procfun) (const char *, void *),
		void *arg)
{
  /* Check whether HEADER matches NAME.  */
  while (*name && (TOLOWER (*name) == TOLOWER (*header)))
    ++name, ++header;
  if (*name || *header++ != ':')
    return 0;

  header += skip_lws (header);

  return ((*procfun) (header, arg));
}

/* Helper functions for use with header_process().  */

/* Extract a long integer from HEADER and store it to CLOSURE.  If an
   error is encountered, return 0, else 1.  */
int
header_extract_number (const char *header, void *closure)
{
  const char *p = header;
  long result;

  for (result = 0; ISDIGIT (*p); p++)
    result = 10 * result + (*p - '0');

  /* Failure if no number present. */
  if (p == header)
    return 0;

  /* Skip trailing whitespace. */
  p += skip_lws (p);

  /* Indicate failure if trailing garbage is present. */
  if (*p)
    return 0;

  *(long *)closure = result;
  return 1;
}

/* Strdup HEADER, and place the pointer to CLOSURE.  */
int
header_strdup (const char *header, void *closure)
{
  *(char **)closure = xstrdup (header);
  return 1;
}

/* Write the value 1 into the integer pointed to by CLOSURE.  */
int
header_exists (const char *header, void *closure)
{
  *(int *)closure = 1;
  return 1;
}

/* Functions to be used as arguments to header_process(): */

struct http_process_range_closure {
  long first_byte_pos;
  long last_byte_pos;
  long entity_length;
};

/* Parse the `Content-Range' header and extract the information it
   contains.  Returns 1 if successful, -1 otherwise.  */
static int
http_process_range (const char *hdr, void *arg)
{
  struct http_process_range_closure *closure
    = (struct http_process_range_closure *)arg;
  long num;

  /* Certain versions of Nutscape proxy server send out
     `Content-Length' without "bytes" specifier, which is a breach of
     RFC2068 (as well as the HTTP/1.1 draft which was current at the
     time).  But hell, I must support it...  */
  if (!strncasecmp (hdr, "bytes", 5))
    {
      hdr += 5;
