       if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
 	report_difference (_("Mode differs"));
 
-#if !MSDOS
-      /* stat() in djgpp's C library gives a constant number of 42 as the
-	 uid and gid of a file.  So, comparing an FTP'ed archive just after
-	 unpack would fail on MSDOS.  */
-      if (stat_data.st_uid != current_stat_info.stat.st_uid)
-	report_difference (_("Uid differs"));
-      if (stat_data.st_gid != current_stat_info.stat.st_gid)
-	report_difference (_("Gid differs"));
-#endif
+      sys_compare_uid_gid (&stat_data, &current_stat_info.stat);
 
       if (stat_data.st_mtime != current_stat_info.stat.st_mtime)
 	report_difference (_("Mod time differs"));
