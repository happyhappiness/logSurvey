	{
	case ACCESS_READ:
	  {
	    enum compress_type type;

	    archive = STDIN_FILENO;

	    type = check_compressed_archive ();
	    if (type != ct_none)
	      FATAL_ERROR ((0, 0,
			    _("Archive is compressed. Use %s option"),
			    compress_option (type)));
	  }
	  break;

