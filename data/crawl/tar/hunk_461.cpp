       ERROR ((0, 0, _("\
 Cannot extract `%s' -- file is continued from another volume"),
 	      current_file_name));
-      skip_file ((long) current_stat.st_size);
+      skip_file (current_stat.st_size);
       if (backup_option)
 	undo_last_backup ();
       break;
