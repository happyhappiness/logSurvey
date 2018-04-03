	  else			/* hstat.res == -1 and contlen is given */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Read error at byte %ld/%ld (%s). "),
			 tms, tmrate, hstat.len, hstat.contlen,
			 strerror (errno));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
