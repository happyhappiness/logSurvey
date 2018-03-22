      else if (typeflag == GNUTYPE_DUMPDIR)
	skip_file (current_stat.st_size);

      if (! prepare_to_extract (CURRENT_FILE_NAME))
	break;

      mode = ((current_stat.st_mode
	       | (we_are_root ? 0 : MODE_WXUSR))
	      & MODE_RWX);

    again_dir:
      status = mkdir (CURRENT_FILE_NAME, mode);
      if (status != 0)
	{
	  if (errno == EEXIST && interdir_made
	      && contains_dot_dot (CURRENT_FILE_NAME))
	    {
	      int e = errno;
	      struct stat st;
	      if (stat (CURRENT_FILE_NAME, &st) == 0)
		{
		  repair_delayed_set_stat (CURRENT_FILE_NAME, &st);
		  break;
		}
	      e = errno;
	    }
	
	  if (maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
	    goto again_dir;

	  if (errno != EEXIST || old_files_option == KEEP_OLD_FILES)
	    {
	      int e = errno;
	      ERROR ((0, e, "%s: mkdir", quotearg_colon (CURRENT_FILE_NAME)));
	      if (backup_option)
		undo_last_backup ();
	      break;
	    }
	}

      if (status == 0
	  || old_files_option == OVERWRITE_OLD_FILES)
	delay_set_stat (CURRENT_FILE_NAME, &current_stat,
			mode & ~ current_stat.st_mode,
			(status == 0
			 ? ARCHIVED_PERMSTATUS
			 : UNKNOWN_PERMSTATUS));
      break;

    case GNUTYPE_VOLHDR:
      if (verbose_option)
	fprintf (stdlis, _("Reading %s\n"), quote (current_file_name));
      break;

    case GNUTYPE_NAMES:
