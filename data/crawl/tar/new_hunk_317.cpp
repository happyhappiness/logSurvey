      ERROR ((0, 0,
	      _("%s: Cannot extract -- file is continued from another volume"),
	      quotearg_colon (current_file_name)));
      skip_member ();
      if (backup_option)
	undo_last_backup ();
      break;
