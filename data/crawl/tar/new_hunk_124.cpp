	      ERROR((1, 0, _("Bad incremental file format")));

	  incremental_version = (errno = 0, strtoumax (ebuf+1, &ebuf, 10));
	}
      else
	incremental_version = 0;

      switch (incremental_version)
	{
	case 0:
	case 1:
	  read_incr_db_01 (incremental_version, buf);
	  break;

	case TAR_INCREMENTAL_VERSION:
	  read_incr_db_2 ();
	  break;
	  
	default:
	  ERROR ((1, 0, _("Unsupported incremental format version: %d"),
		  incremental_version));
	}
      
    }

  if (ferror (listed_incremental_stream))
    read_error (listed_incremental_option);
  if (buf)
    free (buf);
