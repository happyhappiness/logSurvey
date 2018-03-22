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
