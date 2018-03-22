
      while (bufsize > BLOCKSIZE)
	{
	  count = safe_read (file, start->buffer, BLOCKSIZE);
	  if (count < 0)
	    {
	      (ignore_failed_read_option
	       ? read_warn_details
	       : read_error_details)
		(name, fullsize - *sizeleft, bufsize);
	      return 1;
	    }
	  bufsize -= count;
