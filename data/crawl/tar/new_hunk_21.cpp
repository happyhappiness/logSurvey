	      ERROR ((0, errno, "%s:%ld: %s",
		      quotearg_colon (listed_incremental_option), lineno,
		      _("Invalid modification time (nanoseconds)")));
	      mtime.tv_nsec = -1;
	    }
	  else
	    mtime.tv_nsec = u;
	  strp = ebuf;
	}
      else
	mtime.tv_sec = mtime.tv_nsec = 0;

      dev = strtosysint (strp, &ebuf,
			 TYPE_MINIMUM (dev_t), TYPE_MAXIMUM (dev_t));
      strp = ebuf;
      if (errno || *strp != ' ')
	ERROR ((0, errno, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid device number")));

      ino = strtosysint (strp, &ebuf,
			 TYPE_MINIMUM (ino_t), TYPE_MAXIMUM (ino_t));
      strp = ebuf;
      if (errno || *strp != ' ')
	ERROR ((0, errno, "%s:%ld: %s",
		quotearg_colon (listed_incremental_option), lineno,
		_("Invalid inode number")));

      strp++;
      unquote_string (strp);
