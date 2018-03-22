      buf = strdup (initbuf);
      bufsize = strlen (buf) + 1;
    }

  sec = TYPE_MINIMUM (time_t);
  nsec = -1;
  errno = 0;
  u = strtoumax (buf, &ebuf, 10);
  if (!errno && TYPE_MAXIMUM (time_t) < u)
    errno = ERANGE;
  if (errno || buf == ebuf)
    ERROR ((0, errno, "%s:%ld: %s",
	    quotearg_colon (listed_incremental_option),
	    lineno,
	    _("Invalid time stamp")));
  else
    {
      sec = u;

      if (version == 1 && *ebuf)
	{
	  char const *buf_ns = ebuf + 1;
	  errno = 0;
	  u = strtoumax (buf_ns, &ebuf, 10);
	  if (!errno && BILLION <= u)
	    errno = ERANGE;
	  if (errno || buf_ns == ebuf)
	    {
	      ERROR ((0, errno, "%s:%ld: %s",
		      quotearg_colon (listed_incremental_option),
		      lineno,
		      _("Invalid time stamp")));
	      sec = TYPE_MINIMUM (time_t);
	    }
	  else
	    nsec = u;
	}
      else
	{
	  /* pre-1 incremental format does not contain nanoseconds */
	  nsec = 0;
	}
    }
  newer_mtime_option.tv_sec = sec;
  newer_mtime_option.tv_nsec = nsec;


  while (0 < (n = getline (&buf, &bufsize, listed_incremental_stream)))
    {
