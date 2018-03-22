	      WARN ((0, 0, _("Extracting contiguous files as regular files")));
	    }
	}
      fd = open (CURRENT_FILE_NAME, openflag, current_stat.st_mode);

#endif /* not O_CTG */

      if (fd < 0)
	{
	  if (maybe_recoverable (CURRENT_FILE_NAME))
	    goto again_file;

	  ERROR ((0, errno, _("%s: Could not create file"),
		  CURRENT_FILE_NAME));
	  if (current_header->oldgnu_header.isextended)
	    skip_extended_headers ();
	  skip_file (current_stat.st_size);
