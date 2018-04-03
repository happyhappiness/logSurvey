		     tms, hstat.statcode, hstat.error);
	  logputs (LOG_VERBOSE, "\n");
	  FREEHSTAT (hstat);
	  return WRONGCODE;
	}

