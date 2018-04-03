   /* Retrieve the URLs from argument list.  */
   for (t = url; *t; t++)
     {
-      char *filename, *new_file;
+      char *filename, *redirected_URL;
       int dt;
 
-      status = retrieve_url (*t, &filename, &new_file, NULL, &dt);
+      status = retrieve_url (*t, &filename, &redirected_URL, NULL, &dt);
       if (opt.recursive && status == RETROK && (dt & TEXTHTML))
-	status = recursive_retrieve (filename, new_file ? new_file : *t);
-      FREE_MAYBE (new_file);
+	status = recursive_retrieve (filename,
+				     redirected_URL ? redirected_URL : *t);
+
+      if (opt.delete_after && file_exists_p(filename))
+	{
+	  DEBUGP (("Removing file due to --delete-after in main():\n"));
+	  logprintf (LOG_VERBOSE, _("Removing %s.\n"), filename);
+	  if (unlink (filename))
+	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+	}
+
+      FREE_MAYBE (redirected_URL);
       FREE_MAYBE (filename);
     }
 
