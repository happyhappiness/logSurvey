	    if (f < 0)
	      count = bufsize;
	    else
	      count = read (f, start->buffer, (size_t) bufsize);
	    if (count < 0)
	      {
		ERROR ((0, errno, _("\
Read error at byte %ld, reading %d bytes, in file %s"),
			(long) (current_stat.st_size - sizeleft), bufsize, p));
		goto padit;
	      }
	    sizeleft -= count;
