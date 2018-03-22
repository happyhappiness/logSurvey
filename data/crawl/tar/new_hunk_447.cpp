	  count = read (file, start->buffer, BLOCKSIZE);
	  if (count < 0)
	    {
	      char buf[UINTMAX_STRSIZE_BOUND];
	      ERROR ((0, errno, _("\
Read error at byte %s, reading %lu bytes, in file %s"),
		      STRINGIFY_BIGINT (fullsize - *sizeleft, buf),
		      (unsigned long) bufsize, name));
	      return 1;
	    }
	  bufsize -= count;
	  *sizeleft -= count;
	  set_next_block_after (start);
	  start = find_next_block ();
	  memset (start->buffer, 0, BLOCKSIZE);
	}
