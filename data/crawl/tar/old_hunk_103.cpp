      bool nfs = buf[0] == '+';
      char *strp = buf + nfs;
      struct timespec mtime;
      
      lineno++;
      
      if (buf[n - 1] == '\n')
	buf[n - 1] = '\0';
      
      if (version == 1)
	{
	  errno = 0;
	  mtime.tv_sec = u = strtoumax (strp, &ebuf, 10);
	  if (!isspace (*ebuf))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid modification time (seconds)")));
	  else if (mtime.tv_sec != u)
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Modification time (seconds) out of range")));
	  strp = ebuf;
	  
	  errno = 0;
	  mtime.tv_nsec = u = strtoumax (strp, &ebuf, 10);
	  if (!isspace (*ebuf))
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Invalid modification time (nanoseconds)")));
	  else if (mtime.tv_nsec != u)
	    ERROR ((0, 0, "%s:%ld: %s",
		    quotearg_colon (listed_incremental_option), lineno,
		    _("Modification time (nanoseconds) out of range")));
	  strp = ebuf;
	}
      else
	memset (&mtime, 0, sizeof mtime);
      
      errno = 0;
      dev = u = strtoumax (strp, &ebuf, 10);
      if (!isspace (*ebuf))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid device number")));
      else if (dev != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Device number out of range")));
      strp = ebuf;

      errno = 0;
      ino = u = strtoumax (strp, &ebuf, 10);
      if (!isspace (*ebuf))
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid inode number")));
      else if (ino != u)
	ERROR ((0, 0, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Inode number out of range")));
      strp = ebuf;
      
      strp++;
      unquote_string (strp);
      note_directory (strp, mtime, dev, ino, nfs, false, NULL);
