  if (backup_option && !to_stdout_option)
    if (!maybe_backup_file (CURRENT_FILE_NAME, 0))
      {
	ERROR ((0, errno, _("%s: Was unable to backup this file"),
		CURRENT_FILE_NAME));
	if (current_header->oldgnu_header.isextended)
	  skip_extended_headers ();
	skip_file (current_stat.st_size);
