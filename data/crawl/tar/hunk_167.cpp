   return 1;
 }
 
-/* Diff a file against the archive.  */
-void
-diff_archive (void)
+
+static void
+diff_dir ()
 {
   struct stat stat_data;
-  int status;
-  struct utimbuf restore_times;
 
-  set_next_block_after (current_header);
-  decode_header (current_header, &current_stat_info, &current_format, 1);
+  if (!get_stat_data (current_stat_info.file_name, &stat_data))
+    return;
 
-  /* Print the block from current_header and current_stat_info.  */
+  if (!S_ISDIR (stat_data.st_mode))
+    report_difference (&current_stat_info, _("File type differs"));
+  else if ((current_stat_info.stat.st_mode & MODE_ALL) !=
+	   (stat_data.st_mode & MODE_ALL))
+    report_difference (&current_stat_info, _("Mode differs"));
+}
 
-  if (verbose_option)
+static void
+diff_file ()
+{
+  struct stat stat_data;
+
+  if (!get_stat_data (current_stat_info.file_name, &stat_data))
+    skip_member ();
+  else if (!S_ISREG (stat_data.st_mode))
     {
-      if (now_verifying)
-	fprintf (stdlis, _("Verify "));
-      print_header (&current_stat_info, -1);
+      report_difference (&current_stat_info, _("File type differs"));
+      skip_member ();
     }
-
-  switch (current_header->header.typeflag)
+  else
     {
-    default:
-      ERROR ((0, 0, _("%s: Unknown file type '%c', diffed as normal file"),
-	      quotearg_colon (current_stat_info.file_name),
-	      current_header->header.typeflag));
-      /* Fall through.  */
-
-    case AREGTYPE:
-    case REGTYPE:
-    case GNUTYPE_SPARSE:
-    case CONTTYPE:
-
-      /* Appears to be a file.  See if it's really a directory.  */
-
-      if (current_stat_info.had_trailing_slash)
-	goto really_dir;
-
-      if (!get_stat_data (current_stat_info.file_name, &stat_data))
-	{
-	  skip_member ();
-	  goto quit;
-	}
-
-      if (!S_ISREG (stat_data.st_mode))
-	{
-	  report_difference (&current_stat_info, _("File type differs"));
-	  skip_member ();
-	  goto quit;
-	}
-
       if ((current_stat_info.stat.st_mode & MODE_ALL) !=
 	  (stat_data.st_mode & MODE_ALL))
 	report_difference (&current_stat_info, _("Mode differs"));
