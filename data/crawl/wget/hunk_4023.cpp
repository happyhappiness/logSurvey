     {
       /* Construct the backup filename as the original name plus ".orig". */
       size_t         filename_len = strlen(file);
-      char*          filename_plus_orig_suffix = malloc(filename_len +
-							sizeof(".orig"));
+      char*          filename_plus_orig_suffix;
       boolean        already_wrote_backup_file = FALSE;
       slist*         converted_file_ptr;
       static slist*  converted_files = NULL;
 
-      /* Would a single s[n]printf() call be faster? */
-      strcpy(filename_plus_orig_suffix, file);
-      strcpy(filename_plus_orig_suffix + filename_len, ".orig");
+      if (downloaded_file_return == FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED)
+	{
+	  /* Just write "orig" over "html".  We need to do it this way because
+	     when we're checking to see if we've downloaded the file before (to
+	     see if we can skip downloading it), we don't know if it's a
+	     text/html file.  Therefore we don't know yet at that stage that -E
+	     is going to cause us to tack on ".html", so we need to compare
+	     vs. the original URL plus ".orig", not the original URL plus
+	     ".html.orig". */
+	  filename_plus_orig_suffix = xmalloc(filename_len + 1);
+	  strcpy(filename_plus_orig_suffix, file);
+	  strcpy((filename_plus_orig_suffix + filename_len) - 4, "orig");
+	}
+      else /* downloaded_file_return == FILE_DOWNLOADED_NORMALLY */
+	{
+	  /* Append ".orig" to the name. */
+	  filename_plus_orig_suffix = xmalloc(filename_len + sizeof(".orig"));
+	  strcpy(filename_plus_orig_suffix, file);
+	  strcpy(filename_plus_orig_suffix + filename_len, ".orig");
+	}
 
       /* We can get called twice on the same URL thanks to the
 	 convert_all_links() call in main().  If we write the .orig file each
