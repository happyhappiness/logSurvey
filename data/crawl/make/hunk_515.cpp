   check_renamed (file);
   noexist = this_mtime == NONEXISTENT_MTIME;
   if (noexist)
-    DBF (DB_BASIC, _("File `%s' does not exist.\n"));
+    DBF (DB_BASIC, _("File '%s' does not exist.\n"));
   else if (ORDINARY_MTIME_MIN <= this_mtime && this_mtime <= ORDINARY_MTIME_MAX
 	   && file->low_resolution_time)
     {
       /* Avoid spurious rebuilds due to low resolution time stamps.  */
       int ns = FILE_TIMESTAMP_NS (this_mtime);
       if (ns != 0)
-	error (NILF, _("*** Warning: .LOW_RESOLUTION_TIME file `%s' has a high resolution time stamp"),
+	error (NILF, _("*** Warning: .LOW_RESOLUTION_TIME file '%s' has a high resolution time stamp"),
 	       file->name);
       this_mtime += FILE_TIMESTAMPS_PER_S - 1 - ns;
     }
