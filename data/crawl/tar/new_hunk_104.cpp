	    if (!*ebuf)
	      ERROR((1, 0, _("Bad incremental file format")));

	  incremental_version = strtoumax (ebuf + 1, NULL, 10);
	}
      else
	incremental_version = 0;
