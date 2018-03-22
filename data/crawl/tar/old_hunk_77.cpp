  if (use_compress_program_option)
    {
      switch (wanted_access)
	{
	case ACCESS_READ:
	  child_pid = sys_child_open_for_uncompress ();
	  read_full_records = true;
	  record_end = record_start; /* set up for 1st record = # 0 */
	  break;

	case ACCESS_WRITE:
	  child_pid = sys_child_open_for_compress ();
	  break;

	case ACCESS_UPDATE:
	  abort (); /* Should not happen */
	  break;
	}

      if (!index_file_name
	  && wanted_access == ACCESS_WRITE
	  && strcmp (archive_name_array[0], "-") == 0)
	stdlis = stderr;
    }
  else if (strcmp (archive_name_array[0], "-") == 0)
    {
      read_full_records = true; /* could be a pipe, be safe */
      if (verify_option)
	FATAL_ERROR ((0, 0, _("Cannot verify stdin/stdout archive")));

      switch (wanted_access)
	{
	case ACCESS_READ:
	  {
	    bool shortfile;
	    enum compress_type type;

	    archive = STDIN_FILENO;

	    type = check_compressed_archive (&shortfile);
	    if (type != ct_tar && type != ct_none)
	      FATAL_ERROR ((0, 0,
			    _("Archive is compressed. Use %s option"),
			    compress_option (type)));
	    if (shortfile)
	      ERROR ((0, 0, _("This does not look like a tar archive")));
	  }
	  break;

	case ACCESS_WRITE:
	  archive = STDOUT_FILENO;
	  if (!index_file_name)
	    stdlis = stderr;
	  break;

	case ACCESS_UPDATE:
	  archive = STDIN_FILENO;
	  write_archive_to_stdout = true;
	  record_end = record_start; /* set up for 1st record = # 0 */
	  if (!index_file_name)
	    stdlis = stderr;
	  break;
	}
    }
  else if (verify_option)
    archive = rmtopen (archive_name_array[0], O_RDWR | O_CREAT | O_BINARY,
		       MODE_RW, rsh_command_option);
  else
    switch (wanted_access)
      {
      case ACCESS_READ:
	archive = open_compressed_archive ();
	break;

      case ACCESS_WRITE:
	if (backup_option)
	  {
	    maybe_backup_file (archive_name_array[0], 1);
	    backed_up_flag = 1;
	  }
	archive = rmtcreat (archive_name_array[0], MODE_RW,
			    rsh_command_option);
	break;

      case ACCESS_UPDATE:
	archive = rmtopen (archive_name_array[0],
			   O_RDWR | O_CREAT | O_BINARY,
			   MODE_RW, rsh_command_option);

	switch (check_compressed_archive (NULL))
	  {
	  case ct_none:
	  case ct_tar:
	    break;

	  default:
	    FATAL_ERROR ((0, 0,
			  _("Cannot update compressed archives")));
	  }
	break;
      }

  if (archive < 0
