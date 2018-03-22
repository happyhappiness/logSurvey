 }
 
 static void
-diff_dumpdir (void)
+diff_dumpdir (struct tar_stat_info *dir)
 {
   const char *dumpdir_buffer;
   dev_t dev = 0;
   struct stat stat_data;
 
-  if (deref_stat (current_stat_info.file_name, &stat_data) != 0)
+  if (deref_stat (dir->file_name, &stat_data) != 0)
     {
       if (errno == ENOENT)
-	stat_warn (current_stat_info.file_name);
+	stat_warn (dir->file_name);
       else
-	stat_error (current_stat_info.file_name);
+	stat_error (dir->file_name);
     }
   else
     dev = stat_data.st_dev;
 
-  dumpdir_buffer = directory_contents (scan_directory (&current_stat_info));
+  if (dir->fd == 0)
+    {
+      void (*diag) (char const *) = NULL;
+      int fd = subfile_open (dir->parent, dir->orig_file_name, open_read_flags);
+      if (fd < 0)
+	diag = open_diag;
+      else if (fstat (fd, &dir->stat))
+	diag = stat_diag;
+      else
+	dir->fd = fd;
+      if (diag)
+	{
+	  file_removed_diag (dir->orig_file_name, false, diag);
+	  return;
+	}
+    }      
+  dumpdir_buffer = directory_contents (scan_directory (dir));
 
   if (dumpdir_buffer)
     {
-      if (dumpdir_cmp (current_stat_info.dumpdir, dumpdir_buffer))
-	report_difference (&current_stat_info, _("Contents differ"));
+      if (dumpdir_cmp (dir->dumpdir, dumpdir_buffer))
+	report_difference (dir, _("Contents differ"));
     }
   else
-    read_and_process (&current_stat_info, process_noop);
+    read_and_process (dir, process_noop);
 }
 
 static void
