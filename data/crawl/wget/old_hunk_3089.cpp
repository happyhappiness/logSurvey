	  if (hstat.contlen == -1)
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Read error at byte %ld (%s)."),
			 tms, tmrate, hstat.len, strerror (errno));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
