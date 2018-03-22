	    && st1.st_ino == st2.st_ino)
	  break;

	link_error (current_link_name, CURRENT_FILE_NAME);
	if (backup_option)
	  undo_last_backup ();
      }
