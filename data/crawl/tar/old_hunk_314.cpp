	{
	  ERROR ((0, 0, _("%s: Member name contains `..'"),
		  quotearg_colon (CURRENT_FILE_NAME)));
	  if (current_header->oldgnu_header.isextended)
	    skip_extended_headers ();
	  skip_file (current_stat.st_size);
	  return;
	}
    }

  /* Take a safety backup of a previously existing file.  */

  if (backup_option && !to_stdout_option)
