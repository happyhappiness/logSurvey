
      if (count < 0)
	{
	  (ignore_failed_read_option
	   ? read_warn_details
	   : read_error_details)
	    (name, fullsize - *sizeleft, bufsize);
	  return 1;
	}

      *sizeleft -= count;
      set_next_block_after (start);
    }
  free (sparsearray);
#if 0
