	      if (tml >= tmr &&
		  (hstat.contlen == -1 || local_size == hstat.contlen))
		{
		  logprintf (LOG_VERBOSE, _("\
Server file no newer than local file `%s' -- not retrieving.\n\n"),
			     local_filename);
		  FREEHSTAT (hstat);
		  free(filename_plus_orig_suffix);/*must precede every return!*/
		  return RETROK;
		}
	      else if (tml >= tmr)
