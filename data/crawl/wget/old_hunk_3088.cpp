	  else			/* the same, but not accepted */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Connection closed at byte %ld/%ld. "),
			 tms, tmrate, hstat.len, hstat.contlen);
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
