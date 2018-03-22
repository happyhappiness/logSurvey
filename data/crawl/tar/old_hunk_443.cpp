
      if (f >= 0)
	{
	  close (f);
	  if (atime_preserve_option)
	    utime (p, &restore_times);
	}
