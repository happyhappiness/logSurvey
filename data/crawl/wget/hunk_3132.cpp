 #define HTTP_STATUS_NOT_IMPLEMENTED	501
 #define HTTP_STATUS_BAD_GATEWAY		502
 #define HTTP_STATUS_UNAVAILABLE		503
+
+enum rp {
+  rel_none, rel_name, rel_value, rel_both
+};
+
+struct request {
+  const char *method;
+  char *arg;
+
+  struct request_header {
+    char *name, *value;
+    enum rp release_policy;
+  } *headers;
+  int hcount, hcapacity;
+};
+
+/* Create a new, empty request.  At least request_set_method must be
+   called before the request can be used.  */
+
+static struct request *
+request_new ()
+{
+  struct request *req = xnew0 (struct request);
+  req->hcapacity = 8;
+  req->headers = xnew_array (struct request_header, req->hcapacity);
+  return req;
+}
+
+/* Set the request's method and its arguments.  METH should be a
+   literal string (or it should outlive the request) because it will
+   not be freed.  ARG will be freed by request_free.  */
+
+static void
+request_set_method (struct request *req, const char *meth, char *arg)
+{
+  req->method = meth;
+  req->arg = arg;
+}
+
+/* Return the method string passed with the last call to
+   request_set_method.  */
+
+static const char *
+request_method (const struct request *req)
+{
+  return req->method;
+}
+
+/* Free one header according to the release policy specified with
+   request_set_header.  */
+
+static void
+release_header (struct request_header *hdr)
+{
+  switch (hdr->release_policy)
+    {
+    case rel_none:
+      break;
+    case rel_name:
+      xfree (hdr->name);
+      break;
+    case rel_value:
+      xfree (hdr->value);
+      break;
+    case rel_both:
+      xfree (hdr->name);
+      xfree (hdr->value);
+      break;
+    }
+}
+
+/* Set the request named NAME to VALUE.  Specifically, this means that
+   a "NAME: VALUE\r\n" header line will be used in the request.  If a
+   header with the same name previously existed in the request, its
+   value will be replaced by this one.
+
+   RELEASE_POLICY determines whether NAME and VALUE should be released
+   (freed) with request_free.  Allowed values are:
+
+    - rel_none     - don't free NAME or VALUE
+    - rel_name     - free NAME when done
+    - rel_value    - free VALUE when done
+    - rel_both     - free both NAME and VALUE when done
+
+   Setting release policy is useful when arguments come from different
+   sources.  For example:
+
+     // Don't free literal strings!
+     request_set_header (req, "Pragma", "no-cache", rel_none);
+
+     // Don't free a global variable, we'll need it later.
+     request_set_header (req, "Referer", opt.referer, rel_none);
+
+     // Value freshly allocated, free it when done.
+     request_set_header (req, "Range", aprintf ("bytes=%ld-", hs->restval),
+			 rel_value);
+   */
+
+static void
+request_set_header (struct request *req, char *name, char *value,
+		    enum rp release_policy)
+{
+  struct request_header *hdr;
+  int i;
+  if (!value)
+    return;
+  for (i = 0; i < req->hcount; i++)
+    {
+      hdr = &req->headers[i];
+      if (0 == strcasecmp (name, hdr->name))
+	{
+	  /* Replace existing header. */
+	  release_header (hdr);
+	  hdr->name = name;
+	  hdr->value = value;
+	  hdr->release_policy = release_policy;
+	  return;
+	}
+    }
+
+  /* Install new header. */
+
+  if (req->hcount >= req->hcount)
+    {
+      req->hcapacity <<= 1;
+      req->headers = xrealloc (req->headers,
+			       req->hcapacity * sizeof (struct request_header));
+    }
+  hdr = &req->headers[req->hcount++];
+  hdr->name = name;
+  hdr->value = value;
+  hdr->release_policy = release_policy;
+}
+
+/* Like request_set_header, but sets the whole header line, as
+   provided by the user using the `--header' option.  For example,
+   request_set_user_header (req, "Foo: bar") works just like
+   request_set_header (req, "Foo", "bar").  */
+
+static void
+request_set_user_header (struct request *req, const char *header)
+{
+  char *name;
+  const char *p = strchr (header, ':');
+  if (!p)
+    return;
+  BOUNDED_TO_ALLOCA (header, p, name);
+  ++p;
+  while (ISSPACE (*p))
+    ++p;
+  request_set_header (req, xstrdup (name), (char *) p, rel_name);
+}
+
+#define APPEND(p, str) do {			\
+  int A_len = strlen (str);			\
+  memcpy (p, str, A_len);			\
+  p += A_len;					\
+} while (0)
+
+/* Construct the request and write it to FD using fd_write.  */
+
+static int
+request_send (const struct request *req, int fd)
+{
+  char *request_string, *p;
+  int i, size, write_error;
+
+  /* Count the request size. */
+  size = 0;
+
+  /* METHOD " " ARG " " "HTTP/1.0" "\r\n" */
+  size += strlen (req->method) + 1 + strlen (req->arg) + 1 + 8 + 2;
+
+  for (i = 0; i < req->hcount; i++)
+    {
+      struct request_header *hdr = &req->headers[i];
+      /* NAME ": " VALUE "\r\n" */
+      size += strlen (hdr->name) + 2 + strlen (hdr->value) + 2;
+    }
+
+  /* "\r\n\0" */
+  size += 3;
+
+  p = request_string = alloca_array (char, size);
 
+  /* Generate the request. */
+
+  APPEND (p, req->method); *p++ = ' ';
+  APPEND (p, req->arg);    *p++ = ' ';
+  memcpy (p, "HTTP/1.0\r\n", 10); p += 10;
+
+  for (i = 0; i < req->hcount; i++)
+    {
+      struct request_header *hdr = &req->headers[i];
+      APPEND (p, hdr->name);
+      *p++ = ':', *p++ = ' ';
+      APPEND (p, hdr->value);
+      *p++ = '\r', *p++ = '\n';
+    }
+
+  *p++ = '\r', *p++ = '\n', *p++ = '\0';
+  assert (p - request_string == size);
+
+#undef APPEND
+
+  DEBUGP (("\n---request begin---\n%s---request end---\n", request_string));
+
+  /* Send the request to the server. */
+
+  write_error = fd_write (fd, request_string, size - 1, -1);
+  if (write_error < 0)
+    logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
+	       strerror (errno));
+  return write_error;
+}
+
+/* Release the resources used by REQ. */
+
+static void
+request_free (struct request *req)
+{
+  int i;
+  xfree_null (req->arg);
+  for (i = 0; i < req->hcount; i++)
+    release_header (&req->headers[i]);
+  xfree_null (req->headers);
+  xfree (req);
+}
+
 static const char *
 head_terminator (const char *hunk, int oldlen, int peeklen)
 {
