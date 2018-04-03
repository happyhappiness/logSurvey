	      logprintf (LOG_NOTQUIET,
			 _("ERROR: Redirection (%d) without location.\n"),
			 hstat.statcode);
	      free_hstat (&hstat);
	      FREE_MAYBE (dummy);
	      return WRONGCODE;
	    }
	  free_hstat (&hstat);
	  FREE_MAYBE (dummy);
	  return NEWLOCATION;
	  break;
	case RETRUNNEEDED:
	  /* The file was already fully retrieved. */
	  free_hstat (&hstat);
	  FREE_MAYBE (dummy);
	  return RETROK;
	  break;
	case RETRFINISHED:
