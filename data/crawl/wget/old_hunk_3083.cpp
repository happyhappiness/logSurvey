		}
	      else if (tml >= tmr)
		logprintf (LOG_VERBOSE, _("\
The sizes do not match (local %ld) -- retrieving.\n"), local_size);
	      else
		logputs (LOG_VERBOSE,
			 _("Remote file is newer, retrieving.\n"));
