
	  if (errno != EEXIST || old_files_option == KEEP_OLD_FILES)
	    {
	      mkdir_error (CURRENT_FILE_NAME);
	      if (backup_option)
		undo_last_backup ();
	      break;
