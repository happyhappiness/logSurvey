 
 #if S_IFCHR || S_IFBLK
     make_node:
-      if (to_stdout_option)
-	break;
-
-      if (!unlink_destination (CURRENT_FILE_NAME))
+      if (! prepare_to_extract (CURRENT_FILE_NAME))
 	break;
 
       status = mknod (CURRENT_FILE_NAME, current_stat.st_mode,
 		      current_stat.st_rdev);
       if (status != 0)
 	{
-	  if (maybe_recoverable (CURRENT_FILE_NAME))
+	  if (maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
 	    goto make_node;
-
-	  ERROR ((0, errno, _("%s: Could not make node"), CURRENT_FILE_NAME));
+	  mknod_error (CURRENT_FILE_NAME);
 	  if (backup_option)
 	    undo_last_backup ();
 	  break;
 	};
-      set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+      set_stat (CURRENT_FILE_NAME, &current_stat, 0,
+		ARCHIVED_PERMSTATUS, typeflag);
       break;
 #endif
 
 #if HAVE_MKFIFO || defined mkfifo
     case FIFOTYPE:
-      if (to_stdout_option)
-	break;
-
-      if (!unlink_destination (CURRENT_FILE_NAME))
+      if (! prepare_to_extract (CURRENT_FILE_NAME))
 	break;
 
       while (status = mkfifo (CURRENT_FILE_NAME, current_stat.st_mode),
 	     status != 0)
-	if (!maybe_recoverable (CURRENT_FILE_NAME))
+	if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
 	  break;
 
       if (status == 0)
-	set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+	set_stat (CURRENT_FILE_NAME, &current_stat, 0,
+		  ARCHIVED_PERMSTATUS, typeflag);
       else
 	{
-	  ERROR ((0, errno, _("%s: Could not make fifo"), CURRENT_FILE_NAME));
+	  mkfifo_error (CURRENT_FILE_NAME);
 	  if (backup_option)
 	    undo_last_backup ();
 	}