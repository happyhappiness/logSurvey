
	  if (errno != EEXIST || old_files_option == KEEP_OLD_FILES)
	    {
	      int e = errno;
	      ERROR ((0, e, "%s: mkdir", quotearg_colon (CURRENT_FILE_NAME)));
	      if (backup_option)
		undo_last_backup ();
	      break;
