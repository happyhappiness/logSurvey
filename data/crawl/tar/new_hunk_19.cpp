      bufsize = strlen (buf) + 1;
    }

  newer_mtime_option = decode_timespec (buf, &ebuf, false);

  if (! valid_timespec (newer_mtime_option))
    ERROR ((0, errno, "%s:%ld: %s",
	    quotearg_colon (listed_incremental_option),
	    lineno,
	    _("Invalid time stamp")));
  else
    {
      if (version == 1 && *ebuf)
	{
	  char const *buf_ns = ebuf + 1;
