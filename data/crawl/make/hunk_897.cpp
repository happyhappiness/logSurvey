   noexist = this_mtime == NONEXISTENT_MTIME;
   if (noexist)
     DBF (DB_BASIC, _("File `%s' does not exist.\n"));
-  else
+  else if (ORDINARY_MTIME_MIN <= this_mtime && this_mtime <= ORDINARY_MTIME_MAX
+	   && file->low_resolution_time)
     {
-#ifndef NO_ARCHIVES
-      /* Avoid spurious rebuilds of archive members due to their
-         timestamp resolution being only one second.  */
-      if (1 < FILE_TIMESTAMPS_PER_S && ar_name (file->name))
-	this_mtime += FILE_TIMESTAMPS_PER_S - 1;
-#endif
+      /* Avoid spurious rebuilds due to low resolution time stamps.  */
+      int ns = FILE_TIMESTAMP_NS (this_mtime);
+      if (ns != 0)
+	error (NILF, _("*** Warning: .LOW_RESOLUTION_TIME file `%s' has a high resolution time stamp"),
+	       file->name);
+      this_mtime += FILE_TIMESTAMPS_PER_S - 1 - ns;
     }
 
   must_make = noexist;
