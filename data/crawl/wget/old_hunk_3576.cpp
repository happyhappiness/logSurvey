		logputs (LOG_VERBOSE,
			 _("Remote file is newer, retrieving.\n"));
	    }
	  FREEHSTAT (hstat);
	  continue;
	}
      if ((tmr != (time_t) (-1))
