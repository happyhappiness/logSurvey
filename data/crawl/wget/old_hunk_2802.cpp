  if (dp->initial_length)
    {
      int dot_bytes = opt.dot_bytes;
      wgint row_bytes = opt.dot_bytes * opt.dots_in_line;

      int remainder = dp->initial_length % row_bytes;
      wgint skipped = dp->initial_length - remainder;

      if (skipped)
	{
	  int skipped_k = skipped / 1024; /* skipped amount in K */
	  int skipped_k_len = numdigit (skipped_k);
	  if (skipped_k_len < 5)
	    skipped_k_len = 5;

	  /* Align the [ skipping ... ] line with the dots.  To do
	     that, insert the number of spaces equal to the number of
	     digits in the skipped amount in K.  */
	  logprintf (LOG_VERBOSE, _("\n%*s[ skipping %dK ]"),
		     2 + skipped_k_len, "", skipped_k);
	}

      logprintf (LOG_VERBOSE, "\n%5ldK", (long) (skipped / 1024));
      for (; remainder >= dot_bytes; remainder -= dot_bytes)
	{
	  if (dp->dots % opt.dot_spacing == 0)
