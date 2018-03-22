 	    && st1.st_ino == st2.st_ino)
 	  break;
 
-	ERROR ((0, e, _("%s: Cannot link to %s"),
-		quotearg_colon (CURRENT_FILE_NAME),
-		quote (current_link_name)));
+	link_error (current_link_name, CURRENT_FILE_NAME);
 	if (backup_option)
 	  undo_last_backup ();
       }
