   statcode = resp_status (resp, &message);
   if (!opt.server_response)
     logprintf (LOG_VERBOSE, "%2d %s\n", statcode,
-	       message ? escnonprint (message) : "");
+               message ? escnonprint (message) : "");
   else
     {
       logprintf (LOG_VERBOSE, "\n");
       print_server_response (resp, "  ");
     }
 
+  DEBUGP(("in gethttp 4\n"));
+  
+  /* Determine the local filename if needed. Notice that if -O is used 
+   * hstat.local_file is set by http_loop to the argument of -O. */
+  if (!hs->local_file)     
+    {
+      if (resp_header_copy (resp, "Content-Disposition", hdrval, sizeof (hdrval)))
+        /* Honor Content-Disposition. */
+        {
+          hs->local_file = xstrdup (hdrval);
+        }
+      else
+        /* Choose filename according to URL name. */
+        {
+          hs->local_file = url_file_name (u);
+        }
+    }
+  
+  DEBUGP(("in gethttp 5\n"));
+
+  /* TODO: perform this check only once. */
+  if (opt.noclobber && file_exists_p (hs->local_file))
+    {
+      /* If opt.noclobber is turned on and file already exists, do not
+         retrieve the file */
+      logprintf (LOG_VERBOSE, _("\
+File `%s' already there; not retrieving.\n\n"), hs->local_file);
+      /* If the file is there, we suppose it's retrieved OK.  */
+      *dt |= RETROKF;
+
+      /* #### Bogusness alert.  */
+      /* If its suffix is "html" or "htm" or similar, assume text/html.  */
+      if (has_html_suffix_p (hs->local_file))
+        *dt |= TEXTHTML;
+
+      return RETROK;
+    }
+
+  /* Support timestamping */
+  /* TODO: move this code out of gethttp. */
+  if (opt.timestamping && !hs->timestamp_checked)
+    {
+      size_t filename_len = strlen (hs->local_file);
+      char *filename_plus_orig_suffix = alloca (filename_len + sizeof (".orig"));
+      bool local_dot_orig_file_exists = false;
+      char *local_filename = NULL;
+      struct_stat st;
+
+      if (opt.backup_converted)
+        /* If -K is specified, we'll act on the assumption that it was specified
+           last time these files were downloaded as well, and instead of just
+           comparing local file X against server file X, we'll compare local
+           file X.orig (if extant, else X) against server file X.  If -K
+           _wasn't_ specified last time, or the server contains files called
+           *.orig, -N will be back to not operating correctly with -k. */
+        {
+          /* Would a single s[n]printf() call be faster?  --dan
+
+             Definitely not.  sprintf() is horribly slow.  It's a
+             different question whether the difference between the two
+             affects a program.  Usually I'd say "no", but at one
+             point I profiled Wget, and found that a measurable and
+             non-negligible amount of time was lost calling sprintf()
+             in url.c.  Replacing sprintf with inline calls to
+             strcpy() and number_to_string() made a difference.
+             --hniksic */
+          memcpy (filename_plus_orig_suffix, hs->local_file, filename_len);
+          memcpy (filename_plus_orig_suffix + filename_len,
+                  ".orig", sizeof (".orig"));
+
+          /* Try to stat() the .orig file. */
+          if (stat (filename_plus_orig_suffix, &st) == 0)
+            {
+              local_dot_orig_file_exists = 1;
+              local_filename = filename_plus_orig_suffix;
+            }
+        }      
+
+      if (!local_dot_orig_file_exists)
+        /* Couldn't stat() <file>.orig, so try to stat() <file>. */
+        if (stat (hs->local_file, &st) == 0)
+          local_filename = hs->local_file;
+
+      if (local_filename != NULL)
+        /* There was a local file, so we'll check later to see if the version
+           the server has is the same version we already have, allowing us to
+           skip a download. */
+        {
+          hs->orig_file_name = xstrdup (local_filename);
+          hs->orig_file_size = st.st_size;
+          hs->orig_file_tstamp = st.st_mtime;
+#ifdef WINDOWS
+          /* Modification time granularity is 2 seconds for Windows, so
+             increase local time by 1 second for later comparison. */
+          ++hs->orig_file_tstamp;
+#endif
+        }
+    }
+
   if (!opt.ignore_length
       && resp_header_copy (resp, "Content-Length", hdrval, sizeof (hdrval)))
     {
