      status = close (fd);
      if (status < 0)
	{
	  ERROR ((0, errno, _("%s: Error while closing"), CURRENT_FILE_NAME));
	  if (backup_option)
	    undo_last_backup ();
	}

      set_stat (CURRENT_FILE_NAME, &current_stat, 0);
      break;

    case SYMTYPE:
      if (to_stdout_option)
	break;

#ifdef HAVE_SYMLINK
      if (!unlink_destination (CURRENT_FILE_NAME))
	break;

      while (status = symlink (current_link_name, CURRENT_FILE_NAME),
	     status != 0)
	if (!maybe_recoverable (CURRENT_FILE_NAME))
	  break;

      if (status == 0)
