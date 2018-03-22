      char *ebuf;
      int n;
      long lineno = 1;
      uintmax_t u;
      time_t t = u;
      int incremental_version;
      
      if (strncmp (buf, PACKAGE_NAME, sizeof PACKAGE_NAME - 1) == 0)
	{
	  ebuf = buf + sizeof PACKAGE_NAME - 1;
	  if (*ebuf++ != '-')
	    ERROR((1, 0, _("Bad incremental file format")));
	  for (; *ebuf != '-'; ebuf++)
	    if (!*ebuf)
	      ERROR((1, 0, _("Bad incremental file format")));
	  
	  incremental_version = (errno = 0, strtoumax (ebuf+1, &ebuf, 10));
	  if (getline (&buf, &bufsize, fp) <= 0)
	    {
	      read_error (listed_incremental_option);
	      free (buf);
	      return;
	    }
	  ++lineno;
	}
      else
	incremental_version = 0;

      if (incremental_version > TAR_INCREMENTAL_VERSION)
	ERROR((1, 0, _("Unsupported incremental format version: %s"),
	       incremental_version));
      
      t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
      if (buf == ebuf || (u == 0 && errno == EINVAL))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option),
		lineno,
		_("Invalid time stamp")));
      else if (t != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option),
		lineno,
		_("Time stamp out of range")));
      else if (incremental_version == 1)
	{
	  newer_mtime_option.tv_sec = t;
	  
	  t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
	  if (buf == ebuf || (u == 0 && errno == EINVAL))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option),
		    lineno,
		    _("Invalid time stamp")));
	  else if (t != u)
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option),
		    lineno,
		    _("Time stamp out of range")));
	  newer_mtime_option.tv_nsec = t;
	}
      else
	{
	  /* pre-1 incremental format does not contain nanoseconds */
	  newer_mtime_option.tv_sec = t;
	  newer_mtime_option.tv_nsec = 0;
	}
