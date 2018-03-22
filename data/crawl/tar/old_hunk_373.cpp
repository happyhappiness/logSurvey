      if (count < 0)
	{
	  char buf[UINTMAX_STRSIZE_BOUND];
	  
	  ERROR ((0, errno,
		  _("Read error at byte %s, reading %lu bytes, in file %s"),
		  STRINGIFY_BIGINT (fullsize - *sizeleft, buf),
		  (unsigned long) bufsize, name));
	  return 1;
	}
#if 0
