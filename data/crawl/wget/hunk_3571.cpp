     logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));
 
   /* Determine the local filename.  */
-  if (!u->local)
-    u->local = url_filename (u->proxy ? u->proxy : u);
+  if (local_file && *local_file)
+    hstat.local_file = local_file;
+  else if (local_file)
+    {
+      *local_file = url_filename (u);
+      hstat.local_file = local_file;
+    }
+  else
+    {
+      dummy = url_filename (u);
+      hstat.local_file = &dummy;
+    }
 
   if (!opt.output_document)
-    locf = u->local;
+    locf = *hstat.local_file;
   else
     locf = opt.output_document;
 
-  filename_len = strlen (u->local);
+  hstat.referer = referer;
+
+  filename_len = strlen (*hstat.local_file);
   filename_plus_orig_suffix = alloca (filename_len + sizeof (".orig"));
 
-  if (opt.noclobber && file_exists_p (u->local))
+  if (opt.noclobber && file_exists_p (*hstat.local_file))
     {
       /* If opt.noclobber is turned on and file already exists, do not
 	 retrieve the file */
       logprintf (LOG_VERBOSE, _("\
-File `%s' already there, will not retrieve.\n"), u->local);
+File `%s' already there, will not retrieve.\n"), *hstat.local_file);
       /* If the file is there, we suppose it's retrieved OK.  */
       *dt |= RETROKF;
 
       /* #### Bogusness alert.  */
-      /* If its suffix is "html" or (yuck!) "htm", we suppose it's
-	 text/html, a harmless lie.  */
-      if (((suf = suffix (u->local)) != NULL)
+      /* If its suffix is "html" or "htm", assume text/html.  */
+      if (((suf = suffix (*hstat.local_file)) != NULL)
 	  && (!strcmp (suf, "html") || !strcmp (suf, "htm")))
 	*dt |= TEXTHTML;
       xfree (suf);
-      /* Another harmless lie: */
+
+      FREE_MAYBE (dummy);
       return RETROK;
     }
 
