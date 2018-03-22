	{
	case ACCESS_READ:
	  {
	    bool shortfile;
	    enum compress_type type;

	    archive = STDIN_FILENO;

	    type = check_compressed_archive (&shortfile);
	    if (type != ct_none)
	      FATAL_ERROR ((0, 0,
			    _("Archive is compressed. Use %s option"),
			    compress_option (type)));
	    if (shortfile)
	      ERROR ((0, 0, _("This does not look like a tar archive")));
	  }
	  break;

