
      if (skipped)
	{
	  int skipped_k = (int) (skipped / 1024); /* skipped amount in K */
	  int skipped_k_len = numdigit (skipped_k);
	  if (skipped_k_len < 5)
	    skipped_k_len = 5;

	  /* Align the [ skipping ... ] line with the dots.  To do
	     that, insert the number of spaces equal to the number of
	     digits in the skipped amount in K.  */
	  logprintf (LOG_VERBOSE, "\n%*s%s",
		     2 + skipped_k_len, "", _("[ skipping %dK ]"));
	}

      logprintf (LOG_VERBOSE, "\n%5ldK", skipped / 1024);
