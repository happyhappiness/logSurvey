	  /* Align the [ skipping ... ] line with the dots.  To do
	     that, insert the number of spaces equal to the number of
	     digits in the skipped amount in K.  */
	  logprintf (LOG_VERBOSE, _("\n%*s[ skipping %dK ]"),
		     2 + skipped_k_len, "", skipped_k);
	}

      logprintf (LOG_VERBOSE, "\n%5ldK", skipped / 1024);
