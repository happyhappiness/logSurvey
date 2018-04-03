	      if (tml >= tmr &&
		  (hstat.contlen == -1 || local_size == hstat.contlen))
		{
		  logprintf (LOG_VERBOSE, _("\
Local file `%s' is more recent, not retrieving.\n\n"), u->local);
		  FREEHSTAT (hstat);
		  return RETROK;
		}
	      else if (tml >= tmr)
		logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %ld), retrieving.\n"), local_size);
	      else
		logputs (LOG_VERBOSE,
			 _("Remote file is newer, retrieving.\n"));
