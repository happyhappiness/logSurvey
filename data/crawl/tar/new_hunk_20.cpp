
      if (version == 1)
	{
	  mtime = decode_timespec (strp, &ebuf, false);
	  strp = ebuf;
	  if (!valid_timespec (mtime) || *strp != ' ')
	    ERROR ((0, errno, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid modification time")));

	  errno = 0;
	  u = strtoumax (strp, &ebuf, 10);
