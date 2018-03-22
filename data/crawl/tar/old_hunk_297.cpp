	  archive_read_error ();

      if (status == 0)
	{
	  if (left % BLOCKSIZE != 0)
	    ERROR ((0, 0, _("%d garbage bytes ignored at end of archive"),
		    (int) ((record_size - left) % BLOCKSIZE)));
	  break;
	}

      if (! read_full_records_option)
	FATAL_ERROR ((0, 0, _("Unaligned block (%lu bytes) in archive"),
