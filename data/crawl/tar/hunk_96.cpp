 
   if (dumpdir_buffer)
     {
-      dumpdir_cursor = dumpdir_buffer;
-      read_and_process (&current_stat_info, process_dumpdir);
-      free (dumpdir_buffer);
+      if (dumpdir_cmp (current_stat_info.dumpdir, dumpdir_buffer))
+	report_difference (&current_stat_info, _("Contents differ"));
     }
   else
     read_and_process (&current_stat_info, process_noop);
