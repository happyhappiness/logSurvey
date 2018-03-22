	    if (!*ebuf)
	      ERROR((1, 0, _("Bad incremental file format")));

	  incremental_version = (errno = 0, strtoumax (ebuf+1, &ebuf, 10));
	}
      else
	incremental_version = 0;
