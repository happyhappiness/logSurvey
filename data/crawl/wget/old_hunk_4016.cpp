	      logprintf (LOG_NOTQUIET,
			 _("ERROR: Redirection (%d) without location.\n"),
			 hstat.statcode);
	      return WRONGCODE;
	    }
	  FREEHSTAT (hstat);
	  return NEWLOCATION;
	  break;
	case RETRFINISHED: