      status = close (fd);
      if (status < 0)
	{
	  close_error (CURRENT_FILE_NAME);
	  if (backup_option)
	    undo_last_backup ();
	}

      set_stat (CURRENT_FILE_NAME, &current_stat, 0,
		(old_files_option == OVERWRITE_OLD_FILES
		 ? UNKNOWN_PERMSTATUS
		 : ARCHIVED_PERMSTATUS),
		typeflag);
      break;

    case SYMTYPE:
#ifdef HAVE_SYMLINK
      if (! prepare_to_extract (CURRENT_FILE_NAME))
	break;

      while (status = symlink (current_link_name, CURRENT_FILE_NAME),
	     status != 0)
	if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
	  break;

      if (status == 0)
