	{
	  ERROR ((0, 0, _("%s: Member name contains `..'"),
		  quotearg_colon (CURRENT_FILE_NAME)));
	  skip_member ();
	  return;
	}
    }

  apply_nonancestor_delayed_set_stat (CURRENT_FILE_NAME);

  /* Take a safety backup of a previously existing file.  */

  if (backup_option && !to_stdout_option)
