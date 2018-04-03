						 connection too soon */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Connection closed at byte %ld. "),
			 tms, tmrate, hstat.len);
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
