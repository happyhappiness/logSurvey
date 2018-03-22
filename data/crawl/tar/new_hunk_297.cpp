	  archive_read_error ();

      if (status == 0)
	break;

      if (! read_full_records_option)
	FATAL_ERROR ((0, 0, _("Unaligned block (%lu bytes) in archive"),
