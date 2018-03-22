  /* Print the block from current_header and current_stat.  */

  if (verbose_option)
    print_header (-1);

  file_name = safer_name_suffix (current_file_name, 0);

  apply_nonancestor_delayed_set_stat (file_name, 0);

  /* Take a safety backup of a previously existing file.  */

  if (backup_option && !to_stdout_option)
    if (!maybe_backup_file (file_name, 0))
      {
	int e = errno;
	ERROR ((0, e, _("%s: Was unable to backup this file"),
		quotearg_colon (file_name)));
	skip_member ();
	return;
      }
