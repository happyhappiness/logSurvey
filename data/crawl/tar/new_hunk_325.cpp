{
  union block *start;
  size_t bufsize;
  int sparses = 0;
  ssize_t count;

  while (*sizeleft > 0)
    {
      start = find_next_block ();
      memset (start->buffer, 0, BLOCKSIZE);
      bufsize = sparsearray[sparses].numbytes;
      if (! bufsize)
	abort ();

      if (lseek (file, sparsearray[sparses++].offset, SEEK_SET) < 0)
	{
	  (ignore_failed_read_option ? seek_warn_details : seek_error_details)
	    (name, sparsearray[sparses - 1].offset);
	  break;
	}

