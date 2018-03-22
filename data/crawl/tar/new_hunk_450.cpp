	    if (f < 0)
	      count = bufsize;
	    else
	      count = read (f, start->buffer, bufsize);
	    if (count < 0)
	      {
		char buf[UINTMAX_STRSIZE_BOUND];
		ERROR ((0, errno, _("\
Read error at byte %s, reading %lu bytes, in file %s"),
			STRINGIFY_BIGINT (current_stat.st_size - sizeleft,
					  buf),
			(unsigned long) bufsize, p));
		goto padit;
	      }
	    sizeleft -= count;
