  if (dp->initial_length)
    {
      int dot_bytes = opt.dot_bytes;
      const wgint ROW_BYTES = opt.dot_bytes * opt.dots_in_line;

      int remainder = dp->initial_length % ROW_BYTES;
      wgint skipped = dp->initial_length - remainder;

      if (skipped)
	{
	  wgint skipped_k = skipped / 1024; /* skipped amount in K */
	  int skipped_k_len = numdigit (skipped_k);
	  if (skipped_k_len < 6)
	    skipped_k_len = 6;

	  /* Align the [ skipping ... ] line with the dots.  To do
	     that, insert the number of spaces equal to the number of
	     digits in the skipped amount in K.  */
	  logprintf (LOG_VERBOSE, _("\n%*s[ skipping %sK ]"),
		     2 + skipped_k_len, "",
		     number_to_static_string (skipped_k));
	}

      logprintf (LOG_VERBOSE, "\n%6sK",
		 number_to_static_string (skipped / 1024));
      for (; remainder >= dot_bytes; remainder -= dot_bytes)
	{
	  if (dp->dots % opt.dot_spacing == 0)
