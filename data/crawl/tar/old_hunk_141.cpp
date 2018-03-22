      char *ebuf;
      int n;
      long lineno = 1;
      uintmax_t u = (errno = 0, strtoumax (buf, &ebuf, 10));
      time_t t = u;
      
      if (buf == ebuf || (u == 0 && errno == EINVAL))
	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
		_("Invalid time stamp")));
      else if (t != u)
	ERROR ((0, 0, "%s:1: %s", quotearg_colon (listed_incremental_option),
		_("Time stamp out of range")));
      else
	{
	  /* FIXME: This should also input nanoseconds, but that will be a
	     change in file format.  */
	  newer_mtime_option.tv_sec = t;
	  newer_mtime_option.tv_nsec = 0;
	}
