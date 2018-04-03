     }
 }
 
+/*
+  Simple file fetch.
+
+  Set DESTNAME to the name of the saved file.
+
+  Resume previous download if RESUME is true.  To disable
+  Metalink/HTTP, set METALINK_HTTP to false.
+*/
+uerr_t
+fetch_metalink_file (const char *url_str,
+                     bool resume, bool metalink_http,
+                     const char *filename, char **destname)
+{
+  FILE *_output_stream = output_stream;
+  bool _output_stream_regular = output_stream_regular;
+  char *_output_document = opt.output_document;
+  bool _metalink_http = opt.metalink_over_http;
+
+  char *local_file = NULL;
+
+  uerr_t retr_err = URLERROR;
+
+  struct iri *iri;
+  struct url *url;
+  int url_err;
+
+  /* Parse the URL.  */
+  iri = iri_new ();
+  set_uri_encoding (iri, opt.locale, true);
+  url = url_parse (url_str, &url_err, iri, false);
+
+  if (!url)
+    {
+      char *error = url_error (url_str, url_err);
+      logprintf (LOG_NOTQUIET, "%s: %s.\n", url_str, error);
+      inform_exit_status (retr_err);
+      iri_free (iri);
+      xfree (error);
+      return retr_err;
+    }
+
+  output_stream = NULL;
+
+  if (resume)
+    /* continue previous download */
+    output_stream = fopen (filename, "ab");
+  else
+    /* create a file with an unique name */
+    output_stream = unique_create (filename, true, &local_file);
+
+  output_stream_regular = true;
+
+  /*
+    If output_stream is NULL, the file couldn't be created/opened.
+    This could be due to the impossibility to create a directory tree:
+    * stdio.h (fopen)
+    * src/utils.c (unique_create)
+
+    A call to retrieve_url() can indirectly create a directory tree,
+    when opt.output_document is set to the destination file name and
+    output_stream is left to NULL:
+    * src/http.c (open_output_stream): If output_stream is NULL,
+      create the destination opt.output_document "path/file"
+  */
+  if (!local_file)
+    local_file = xstrdup (filename);
+
+  /* Store the real file name for displaying in messages, and for
+     proper "path/file" handling.  */
+  opt.output_document = local_file;
+
+  opt.metalink_over_http = metalink_http;
+
+  DEBUGP (("Storing to %s\n", local_file));
+  retr_err = retrieve_url (url, url_str, NULL, NULL,
+                           NULL, NULL, opt.recursive, iri, false);
+
+  if (retr_err == RETROK)
+    {
+      if (destname)
+        *destname = local_file;
+      else
+        xfree (local_file);
+    }
+
+  if (output_stream)
+    {
+      fclose (output_stream);
+      output_stream = NULL;
+    }
+
+  opt.metalink_over_http = _metalink_http;
+  opt.output_document = _output_document;
+  output_stream_regular = _output_stream_regular;
+  output_stream = _output_stream;
+
+  inform_exit_status (retr_err);
+
+  iri_free (iri);
+  url_free (url);
+
+  return retr_err;
+}
+
 int metalink_res_cmp (const void* v1, const void* v2)
 {
   const metalink_resource_t *res1 = *(metalink_resource_t **) v1,
