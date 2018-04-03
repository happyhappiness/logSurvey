						 connection too soon */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Connection closed at byte %s. "),
			 tms, tmrate, number_to_static_string (hstat.len));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
