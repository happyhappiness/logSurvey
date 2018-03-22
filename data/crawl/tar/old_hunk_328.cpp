		  count = safe_read (f, start->buffer, bufsize);
		if (count < 0)
		  {
		    char buf[UINTMAX_STRSIZE_BOUND];
		    int e = errno;
		    ERROR ((0, e,
			    _("Read error at byte %s, reading %lu bytes, in file %s"),
			    STRINGIFY_BIGINT (current_stat.st_size - sizeleft,
					      buf),
			    (unsigned long) bufsize, quote (p)));
		    goto padit;
		  }
		sizeleft -= count;
