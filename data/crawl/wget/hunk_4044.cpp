   /* ...to a buffer.  */
   load_file (fp, &buf, &size);
   fclose (fp);
-  if (opt.backup_converted)
+  if (opt.backup_converted && downloaded_file(CHECK_FOR_FILE, file))
     /* Rather than just writing over the original .html file with the converted
-       version, save the former to *.orig. */
+       version, save the former to *.orig.  Note we only do this for files we've
+       _successfully_ downloaded, so we don't clobber .orig files sitting around
+       from previous invocations. */
     {
       /* Construct the backup filename as the original name plus ".orig". */
-      size_t filename_len = strlen(file);
-      char*  filename_plus_orig_suffix = malloc(filename_len + sizeof(".orig"));
-      int    already_wrote_backup_file = 0;
-      slist* converted_file_ptr;
-
+      size_t         filename_len = strlen(file);
+      char*          filename_plus_orig_suffix = malloc(filename_len +
+							sizeof(".orig"));
+      boolean        already_wrote_backup_file = FALSE;
+      slist*         converted_file_ptr;
+      static slist*  converted_files = NULL;
+
+      /* Would a single s[n]printf() call be faster? */
       strcpy(filename_plus_orig_suffix, file);
       strcpy(filename_plus_orig_suffix + filename_len, ".orig");
 
       /* We can get called twice on the same URL thanks to the
 	 convert_all_links() call in main().  If we write the .orig file each
 	 time in such a case, it'll end up containing the first-pass conversion,
-	 not the original file. */
+	 not the original file.  So, see if we've already been called on this
+	 file. */
       converted_file_ptr = converted_files;
       while (converted_file_ptr != NULL)
 	if (strcmp(converted_file_ptr->string, file) == 0)
 	  {
-	    already_wrote_backup_file = 1;
+	    already_wrote_backup_file = TRUE;
 	    break;
 	  }
 	else
