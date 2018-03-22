	case TAR_INCREMENTAL_VERSION:
	  read_incr_db_2 ();
	  break;
	  
	default:
	  ERROR ((1, 0, _("Unsupported incremental format version: %d"),
		  incremental_version));
	}
      
    }

  if (ferror (listed_incremental_stream))
