      if (! prepare_to_extract (CURRENT_FILE_NAME))
	break;

      while (status = symlink (current_link_name, CURRENT_FILE_NAME),
	     status != 0)
	if (!maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
	  break;

      if (status == 0)

	/* Setting the attributes of symbolic links might, on some systems,
	   change the pointed to file, instead of the symbolic link itself.
	   At least some of these systems have a lchown call, and the
	   set_stat routine knows about this.    */

	set_stat (CURRENT_FILE_NAME, &current_stat, 0,
		  ARCHIVED_PERMSTATUS, typeflag);

      else
	{
	  int e = errno;
	  ERROR ((0, e, _("%s: Cannot create symlink to %s"),
		  quotearg_colon (CURRENT_FILE_NAME),
		  quote (current_link_name)));
	  if (backup_option)
	    undo_last_backup ();
	}
      break;

#else
