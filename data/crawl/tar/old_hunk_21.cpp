	      ERROR ((0, errno, "%s:%ld: %s",
		      quotearg_colon (listed_incremental_option), lineno,
		      _("Invalid modification time (nanoseconds)")));
	      nsec = -1;
	    }
	  else
	    nsec = u;
	  mtime.tv_sec = sec;
	  mtime.tv_nsec = nsec;
	  strp = ebuf;
	}
      else
	memset (&mtime, 0, sizeof mtime);

      errno = 0;
      u = strtoumax (strp, &ebuf, 10);
      if (!errno && TYPE_MAXIMUM (dev_t) < u)
	errno = ERANGE;
      if (errno || strp == ebuf || *ebuf != ' ')
	{
	  ERROR ((0, errno, "%s:%ld: %s",
		  quotearg_colon (listed_incremental_option), lineno,
		  _("Invalid device number")));
	  dev = (dev_t) -1;
	}
      else
	dev = u;
      strp = ebuf;

      errno = 0;
      u = strtoumax (strp, &ebuf, 10);
      if (!errno && TYPE_MAXIMUM (ino_t) < u)
	errno = ERANGE;
      if (errno || strp == ebuf || *ebuf != ' ')
	{
	  ERROR ((0, errno, "%s:%ld: %s",
		  quotearg_colon (listed_incremental_option), lineno,
		  _("Invalid inode number")));
	  ino = (ino_t) -1;
	}
      else
	ino = u;
      strp = ebuf;

      strp++;
      unquote_string (strp);
