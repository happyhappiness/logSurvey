		  count = safe_read (f, start->buffer, bufsize);
		if (count < 0)
		  {
		    (ignore_failed_read_option
		     ? read_warn_details
		     : read_error_details)
		      (p, current_stat.st_size - sizeleft, bufsize);
		    goto padit;
		  }
		sizeleft -= count;
