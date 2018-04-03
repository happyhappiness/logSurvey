        text/html file.  If some case-insensitive variation on ".htm[l]" isn't
        already the file's suffix, tack on ".html". */
     {
-      char *last_period_in_local_filename = strrchr (*hs->local_file, '.');
+      char *last_period_in_local_filename = strrchr (hs->local_file, '.');
 
       if (last_period_in_local_filename == NULL
-	  || !(0 == strcasecmp (last_period_in_local_filename, ".htm")
-	       || 0 == strcasecmp (last_period_in_local_filename, ".html")))
-	{
-	  int local_filename_len = strlen (*hs->local_file);
-	  /* Resize the local file, allowing for ".html" preceded by
-	     optional ".NUMBER".  */
-	  *hs->local_file = xrealloc (*hs->local_file,
-				      local_filename_len + 24 + sizeof (".html"));
-	  strcpy(*hs->local_file + local_filename_len, ".html");
-	  /* If clobbering is not allowed and the file, as named,
-	     exists, tack on ".NUMBER.html" instead. */
-	  if (!ALLOW_CLOBBER)
-	    {
-	      int ext_num = 1;
-	      do
-		sprintf (*hs->local_file + local_filename_len,
-			 ".%d.html", ext_num++);
-	      while (file_exists_p (*hs->local_file));
-	    }
-	  *dt |= ADDED_HTML_EXTENSION;
-	}
+          || !(0 == strcasecmp (last_period_in_local_filename, ".htm")
+               || 0 == strcasecmp (last_period_in_local_filename, ".html")))
+        {
+          int local_filename_len = strlen (hs->local_file);
+          /* Resize the local file, allowing for ".html" preceded by
+             optional ".NUMBER".  */
+          hs->local_file = xrealloc (hs->local_file,
+                                     local_filename_len + 24 + sizeof (".html"));
+          strcpy(hs->local_file + local_filename_len, ".html");
+          /* If clobbering is not allowed and the file, as named,
+             exists, tack on ".NUMBER.html" instead. */
+          if (!ALLOW_CLOBBER)
+            {
+              int ext_num = 1;
+              do
+                sprintf (hs->local_file + local_filename_len,
+                         ".%d.html", ext_num++);
+              while (file_exists_p (hs->local_file));
+            }
+          *dt |= ADDED_HTML_EXTENSION;
+        }
     }
 
   if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE)
     {
       /* If `-c' is in use and the file has been fully downloaded (or
-	 the remote file has shrunk), Wget effectively requests bytes
-	 after the end of file and the server response with 416.  */
+         the remote file has shrunk), Wget effectively requests bytes
+         after the end of file and the server response with 416.  */
       logputs (LOG_VERBOSE, _("\
 \n    The file is already fully retrieved; nothing to do.\n\n"));
       /* In case the caller inspects. */
