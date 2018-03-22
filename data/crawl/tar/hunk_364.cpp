       status = close (fd);
       if (status < 0)
 	{
-	  ERROR ((0, errno, _("%s: Error while closing"), CURRENT_FILE_NAME));
+	  close_error (CURRENT_FILE_NAME);
 	  if (backup_option)
 	    undo_last_backup ();
 	}
 
-      set_stat (CURRENT_FILE_NAME, &current_stat, 0);
+      set_stat (CURRENT_FILE_NAME, &current_stat, 0,
+		(old_files_option == OVERWRITE_OLD_FILES
+		 ? UNKNOWN_PERMSTATUS
+		 : ARCHIVED_PERMSTATUS),
+		typeflag);
       break;
 
     case SYMTYPE:
-      if (to_stdout_option)
-	break;
-
 #ifdef HAVE_SYMLINK
-      if (!unlink_destination (CURRENT_FILE_NAME))
+      if (! prepare_to_extract (CURRENT_FILE_NAME))
 	break;
 
       while (status = symlink (current_link_name, CURRENT_FILE_NAME),
 	     status != 0)
-	if (!maybe_recoverable (CURRENT_FILE_NAME))
+	if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
 	  break;
 
       if (status == 0)
