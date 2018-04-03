		  logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"),
			     local_filename);
		  FREEHSTAT (hstat);
		  return RETROK;
		}
	      else if (tml >= tmr)
