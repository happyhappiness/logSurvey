		logputs (LOG_VERBOSE,
			 _("Remote file is newer, retrieving.\n"));
	    }
	  free_hstat (&hstat);
	  continue;
	}
      if ((tmr != (time_t) (-1))
