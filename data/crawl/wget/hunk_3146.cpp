 #define HTTP_STATUS_BAD_GATEWAY		502
 #define HTTP_STATUS_UNAVAILABLE		503
 
-
-/* Parse the HTTP status line, which is of format:
+static const char *
+head_terminator (const char *hunk, int oldlen, int peeklen)
+{
+  const char *start, *end;
 
-   HTTP-Version SP Status-Code SP Reason-Phrase
+  /* If at first peek, verify whether HUNK starts with "HTTP".  If
+     not, this is a HTTP/0.9 request and we must bail out without
+     reading anything.  */
+  if (oldlen == 0 && 0 != memcmp (hunk, "HTTP", MIN (peeklen, 4)))
+    return hunk;
 
-   The function returns the status-code, or -1 if the status line is
-   malformed.  The pointer to reason-phrase is returned in RP.  */
-static int
-parse_http_status_line (const char *line, const char **reason_phrase_ptr)
+  if (oldlen < 4)
+    start = hunk;
+  else
+    start = hunk + oldlen - 4;
+  end = hunk + oldlen + peeklen;
+
+  for (; start < end - 1; start++)
+    if (*start == '\n')
+      {
+	if (start < end - 2
+	    && start[1] == '\r'
+	    && start[2] == '\n')
+	  return start + 3;
+	if (start[1] == '\n')
+	  return start + 2;
+      }
+  return NULL;
+}
+
+/* Read the HTTP request head from FD and return it.  The error
+   conditions are the same as with fd_read_hunk.
+
+   To support HTTP/0.9 responses, this function tries to make sure
+   that the data begins with "HTTP".  If this is not the case, no data
+   is read and an empty request is returned, so that the remaining
+   data can be treated as body.  */
+
+static char *
+fd_read_http_head (int fd)
 {
-  /* (the variables must not be named `major' and `minor', because
-     that breaks compilation with SunOS4 cc.)  */
-  int mjr, mnr, statcode;
-  const char *p;
+  return fd_read_hunk (fd, head_terminator, 512);
+}
 
-  *reason_phrase_ptr = NULL;
+struct response {
+  /* The response data. */
+  const char *data;
+
+  /* The array of pointers that indicate where each header starts.
+     For example, given three headers "foo", "bar", and "baz":
+       foo: value\r\nbar: value\r\nbaz: value\r\n\r\n
+       0             1             2             3
+     I.e. headers[0] points to the beginning of foo, headers[1] points
+     to the end of foo and the beginning of bar, etc.  */
+  const char **headers;
+};
 
-  /* The standard format of HTTP-Version is: `HTTP/X.Y', where X is
-     major version, and Y is minor version.  */
-  if (strncmp (line, "HTTP/", 5) != 0)
-    return -1;
-  line += 5;
+static struct response *
+response_new (const char *head)
+{
+  const char *hdr;
+  int count, size;
 
-  /* Calculate major HTTP version.  */
-  p = line;
-  for (mjr = 0; ISDIGIT (*line); line++)
-    mjr = 10 * mjr + (*line - '0');
-  if (*line != '.' || p == line)
-    return -1;
-  ++line;
+  struct response *resp = xnew0 (struct response);
+  resp->data = head;
 
-  /* Calculate minor HTTP version.  */
-  p = line;
-  for (mnr = 0; ISDIGIT (*line); line++)
-    mnr = 10 * mnr + (*line - '0');
-  if (*line != ' ' || p == line)
-    return -1;
-  /* Wget will accept only 1.0 and higher HTTP-versions.  The value of
-     minor version can be safely ignored.  */
-  if (mjr < 1)
-    return -1;
-  ++line;
+  if (*head == '\0')
+    {
+      /* Empty head means that we're dealing with a headerless
+	 (HTTP/0.9) response.  In that case, don't set HEADERS at
+	 all.  */
+      return resp;
+    }
 
-  /* Calculate status code.  */
-  if (!(ISDIGIT (*line) && ISDIGIT (line[1]) && ISDIGIT (line[2])))
-    return -1;
-  statcode = 100 * (*line - '0') + 10 * (line[1] - '0') + (line[2] - '0');
+  /* Split HEAD into header lines, so that response_header_* functions
+     don't need to do this over and over again.  */
 
-  /* Set up the reason phrase pointer.  */
-  line += 3;
-  /* RFC2068 requires SPC here, but we allow the string to finish
-     here, in case no reason-phrase is present.  */
-  if (*line != ' ')
+  size = count = 0;
+  hdr = head;
+  while (1)
     {
-      if (!*line)
-	*reason_phrase_ptr = line;
-      else
-	return -1;
+      DO_REALLOC (resp->headers, size, count + 1, const char *);
+      resp->headers[count++] = hdr;
+
+      /* Break upon encountering an empty line. */
+      if (!hdr[0] || (hdr[0] == '\r' && hdr[1] == '\n') || hdr[0] == '\n')
+	break;
+
+      /* Find the end of HDR, including continuations. */
+      do
+	{
+	  const char *end = strchr (hdr, '\n');
+	  if (end)
+	    hdr = end + 1;
+	  else
+	    hdr += strlen (hdr);
+	}
+      while (*hdr == ' ' || *hdr == '\t');
     }
-  else
-    *reason_phrase_ptr = line + 1;
+  DO_REALLOC (resp->headers, size, count + 1, const char *);
+  resp->headers[count++] = NULL;
 
-  return statcode;
+  return resp;
 }
-
-#define WMIN(x, y) ((x) > (y) ? (y) : (x))
-
-/* Send the contents of FILE_NAME to SOCK/SSL.  Make sure that exactly
-   PROMISED_SIZE bytes are sent over the wire -- if the file is
-   longer, read only that much; if the file is shorter, report an error.  */
 
 static int
-post_file (int sock, const char *file_name, long promised_size)
+response_header_bounds (const struct response *resp, const char *name,
+			const char **begptr, const char **endptr)
 {
-  static char chunk[8192];
-  long written = 0;
-  int write_error;
-  FILE *fp;
+  int i;
+  const char **headers = resp->headers;
+  int name_len;
 
-  DEBUGP (("[writing POST file %s ... ", file_name));
+  if (!headers || !headers[1])
+    return 0;
 
-  fp = fopen (file_name, "rb");
-  if (!fp)
-    return -1;
-  while (!feof (fp) && written < promised_size)
+  name_len = strlen (name);
+
+  for (i = 1; headers[i + 1]; i++)
     {
-      int towrite;
-      int length = fread (chunk, 1, sizeof (chunk), fp);
-      if (length == 0)
-	break;
-      towrite = WMIN (promised_size - written, length);
-      write_error = fd_write (sock, chunk, towrite, -1);
-      if (write_error < 0)
+      const char *b = headers[i];
+      const char *e = headers[i + 1];
+      if (e - b > name_len
+	  && b[name_len] == ':'
+	  && 0 == strncasecmp (b, name, name_len))
 	{
-	  fclose (fp);
-	  return -1;
+	  b += name_len + 1;
+	  while (b < e && ISSPACE (*b))
+	    ++b;
+	  while (b < e && ISSPACE (e[-1]))
+	    --e;
+	  *begptr = b;
+	  *endptr = e;
+	  return 1;
 	}
-      written += towrite;
     }
-  fclose (fp);
-
-  /* If we've written less than was promised, report a (probably
-     nonsensical) error rather than break the promise.  */
-  if (written < promised_size)
-    {
-      errno = EINVAL;
-      return -1;
-    }
-
-  assert (written == promised_size);
-  DEBUGP (("done]\n"));
   return 0;
 }
-
-static const char *
-next_header (const char *h)
+
+static int
+response_header_copy (const struct response *resp, const char *name,
+		      char *buf, int bufsize)
 {
-  const char *end = NULL;
-  const char *p = h;
-  do
+  const char *b, *e;
+  if (!response_header_bounds (resp, name, &b, &e))
+    return 0;
+  if (bufsize)
     {
-      p = strchr (p, '\n');
-      if (!p)
-	return end;
-      end = ++p;
+      int len = MIN (e - b, bufsize);
+      strncpy (buf, b, len);
+      buf[len] = '\0';
     }
-  while (*p == ' ' || *p == '\t');
-
-  return end;
+  return 1;
 }
 
-/* Skip LWS (linear white space), if present.  Returns number of
-   characters to skip.  */
-static int
-skip_lws (const char *string)
+static char *
+response_header_strdup (const struct response *resp, const char *name)
 {
-  const char *p = string;
-
-  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
-    ++p;
-  return p - string;
+  const char *b, *e;
+  if (!response_header_bounds (resp, name, &b, &e))
+    return NULL;
+  return strdupdelim (b, e);
 }
 
-/* Check whether HEADER begins with NAME and, if yes, skip the `:' and
-   the whitespace, and call PROCFUN with the arguments of HEADER's
-   contents (after the `:' and space) and ARG.  Otherwise, return 0.  */
-int
-header_process (const char *header, const char *name,
-		int (*procfun) (const char *, void *),
-		void *arg)
-{
-  /* Check whether HEADER matches NAME.  */
-  while (*name && (TOLOWER (*name) == TOLOWER (*header)))
-    ++name, ++header;
-  if (*name || *header++ != ':')
-    return 0;
+/* Parse the HTTP status line, which is of format:
 
-  header += skip_lws (header);
+   HTTP-Version SP Status-Code SP Reason-Phrase
 
-  return ((*procfun) (header, arg));
-}
-
-/* Helper functions for use with header_process().  */
+   The function returns the status-code, or -1 if the status line
+   appears malformed.  The pointer to "reason-phrase" message is
+   returned in *MESSAGE.  */
 
-/* Extract a long integer from HEADER and store it to CLOSURE.  If an
-   error is encountered, return 0, else 1.  */
-int
-header_extract_number (const char *header, void *closure)
+static int
+response_status (const struct response *resp, char **message)
 {
-  const char *p = header;
-  long result;
+  int status;
+  const char *p, *end;
 
-  for (result = 0; ISDIGIT (*p); p++)
-    result = 10 * result + (*p - '0');
+  if (!resp->headers)
+    {
+      /* For a HTTP/0.9 response, always assume 200 response. */
+      if (message)
+	*message = xstrdup ("OK");
+      return 200;
+    }
 
-  /* Failure if no number present. */
-  if (p == header)
-    return 0;
+  p = resp->headers[0];
+  end = resp->headers[1];
 
-  /* Skip trailing whitespace. */
-  p += skip_lws (p);
+  if (!end)
+    return -1;
 
-  /* Indicate failure if trailing garbage is present. */
-  if (*p)
-    return 0;
+  /* "HTTP" */
+  if (end - p < 4 || 0 != strncmp (p, "HTTP", 4))
+    return -1;
+  p += 4;
 
-  *(long *)closure = result;
-  return 1;
+  /* "/x.x" (optional because some Gnutella servers have been reported
+     as not sending the "/x.x" part.  */
+  if (p < end && *p == '/')
+    {
+      ++p;
+      while (p < end && ISDIGIT (*p))
+	++p;
+      if (p < end && *p == '.')
+	++p; 
+      while (p < end && ISDIGIT (*p))
+	++p;
+    }
+
+  while (p < end && ISSPACE (*p))
+    ++p;
+  if (end - p < 3 || !ISDIGIT (p[0]) || !ISDIGIT (p[1]) || !ISDIGIT (p[2]))
+    return -1;
+
+  status = 100 * (p[0] - '0') + 10 * (p[1] - '0') + (p[2] - '0');
+  p += 3;
+
+  if (message)
+    {
+      while (p < end && ISSPACE (*p))
+	++p;
+      while (p < end && ISSPACE (end[-1]))
+	--end;
+      *message = strdupdelim (p, end);
+    }
+
+  return status;
 }
 
-/* Strdup HEADER, and place the pointer to CLOSURE.  */
-int
-header_strdup (const char *header, void *closure)
+static void
+response_free (struct response *resp)
 {
-  *(char **)closure = xstrdup (header);
-  return 1;
+  xfree_null (resp->headers);
+  xfree (resp);
 }
 
-/* Write the value 1 into the integer pointed to by CLOSURE.  */
-int
-header_exists (const char *header, void *closure)
+static void
+print_server_response_1 (const char *b, const char *e)
 {
-  *(int *)closure = 1;
-  return 1;
+  char *ln;
+  if (b < e && e[-1] == '\n')
+    --e;
+  if (b < e && e[-1] == '\r')
+    --e;
+  BOUNDED_TO_ALLOCA (b, e, ln);
+  logprintf (LOG_VERBOSE, "  %s\n", ln);
 }
-
-/* Functions to be used as arguments to header_process(): */
 
-struct http_process_range_closure {
-  long first_byte_pos;
-  long last_byte_pos;
-  long entity_length;
-};
+static void
+print_server_response (const struct response *resp)
+{
+  int i;
+  if (!resp->headers)
+    return;
+  for (i = 0; resp->headers[i + 1]; i++)
+    print_server_response_1 (resp->headers[i], resp->headers[i + 1]);
+}
 
 /* Parse the `Content-Range' header and extract the information it
    contains.  Returns 1 if successful, -1 otherwise.  */
 static int
-http_process_range (const char *hdr, void *arg)
+parse_content_range (const char *hdr, long *first_byte_ptr,
+		     long *last_byte_ptr, long *entity_length_ptr)
 {
-  struct http_process_range_closure *closure
-    = (struct http_process_range_closure *)arg;
   long num;
 
-  /* Certain versions of Nutscape proxy server send out
-     `Content-Length' without "bytes" specifier, which is a breach of
-     RFC2068 (as well as the HTTP/1.1 draft which was current at the
-     time).  But hell, I must support it...  */
+  /* Ancient versions of Netscape proxy server, presumably predating
+     rfc2068, sent out `Content-Range' without the "bytes"
+     specifier.  */
   if (!strncasecmp (hdr, "bytes", 5))
     {
       hdr += 5;
