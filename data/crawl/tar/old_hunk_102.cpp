      buf = strdup (initbuf);
      bufsize = strlen (buf) + 1;
    }
  
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
  else if (version == 1)
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

  while (0 < (n = getline (&buf, &bufsize, listed_incremental_stream)))
    {
