
	if (status == 0)
	  break;
	if (maybe_recoverable (CURRENT_FILE_NAME, &interdir_made))
	  goto again_link;

	if (incremental_option && errno == EEXIST)
	  break;
	e = errno;
	if (stat (current_link_name, &st1) == 0
	    && stat (CURRENT_FILE_NAME, &st2) == 0
	    && st1.st_dev == st2.st_dev
	    && st1.st_ino == st2.st_ino)
	  break;

	ERROR ((0, e, _("%s: Cannot link to %s"),
		quotearg_colon (CURRENT_FILE_NAME),
		quote (current_link_name)));
	if (backup_option)
	  undo_last_backup ();
      }
