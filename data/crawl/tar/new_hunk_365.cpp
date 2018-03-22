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
