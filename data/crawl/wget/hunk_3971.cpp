   return t;
 }
 
+static void
+write_backup_file (const char *file, downloaded_file_t downloaded_file_return)
+{
+  /* Rather than just writing over the original .html file with the
+     converted version, save the former to *.orig.  Note we only do
+     this for files we've _successfully_ downloaded, so we don't
+     clobber .orig files sitting around from previous invocations. */
+
+  /* Construct the backup filename as the original name plus ".orig". */
+  size_t         filename_len = strlen(file);
+  char*          filename_plus_orig_suffix;
+  boolean        already_wrote_backup_file = FALSE;
+  slist*         converted_file_ptr;
+  static slist*  converted_files = NULL;
+
+  if (downloaded_file_return == FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED)
+    {
+      /* Just write "orig" over "html".  We need to do it this way
+	 because when we're checking to see if we've downloaded the
+	 file before (to see if we can skip downloading it), we don't
+	 know if it's a text/html file.  Therefore we don't know yet
+	 at that stage that -E is going to cause us to tack on
+	 ".html", so we need to compare vs. the original URL plus
+	 ".orig", not the original URL plus ".html.orig". */
+      filename_plus_orig_suffix = alloca (filename_len + 1);
+      strcpy(filename_plus_orig_suffix, file);
+      strcpy((filename_plus_orig_suffix + filename_len) - 4, "orig");
+    }
+  else /* downloaded_file_return == FILE_DOWNLOADED_NORMALLY */
+    {
+      /* Append ".orig" to the name. */
+      filename_plus_orig_suffix = alloca (filename_len + sizeof(".orig"));
+      strcpy(filename_plus_orig_suffix, file);
+      strcpy(filename_plus_orig_suffix + filename_len, ".orig");
+    }
+
+  /* We can get called twice on the same URL thanks to the
+     convert_all_links() call in main().  If we write the .orig file
+     each time in such a case, it'll end up containing the first-pass
+     conversion, not the original file.  So, see if we've already been
+     called on this file. */
+  converted_file_ptr = converted_files;
+  while (converted_file_ptr != NULL)
+    if (strcmp(converted_file_ptr->string, file) == 0)
+      {
+	already_wrote_backup_file = TRUE;
+	break;
+      }
+    else
+      converted_file_ptr = converted_file_ptr->next;
+
+  if (!already_wrote_backup_file)
+    {
+      /* Rename <file> to <file>.orig before former gets written over. */
+      if (rename(file, filename_plus_orig_suffix) != 0)
+	logprintf (LOG_NOTQUIET, _("Cannot back up %s as %s: %s\n"),
+		   file, filename_plus_orig_suffix, strerror (errno));
+
+      /* Remember that we've already written a .orig backup for this file.
+	 Note that we never free this memory since we need it till the
+	 convert_all_links() call, which is one of the last things the
+	 program does before terminating.  BTW, I'm not sure if it would be
+	 safe to just set 'converted_file_ptr->string' to 'file' below,
+	 rather than making a copy of the string...  Another note is that I
+	 thought I could just add a field to the urlpos structure saying
+	 that we'd written a .orig file for this URL, but that didn't work,
+	 so I had to make this separate list. */
+      converted_file_ptr = xmalloc(sizeof(*converted_file_ptr));
+      converted_file_ptr->string = xstrdup(file);  /* die on out-of-mem. */
+      converted_file_ptr->next = converted_files;
+      converted_files = converted_file_ptr;
+    }
+}
 
 /* Remembers which files have been downloaded.  In the standard case, should be
    called with mode == FILE_DOWNLOADED_NORMALLY for each file we actually
