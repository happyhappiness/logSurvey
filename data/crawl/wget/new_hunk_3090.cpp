	  else			/* hstat.res == -1 and contlen is given */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Read error at byte %s/%s (%s). "),
			 tms, tmrate,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen),
			 strerror (errno));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
