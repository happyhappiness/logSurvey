	      logprintf (LOG_NOTQUIET,
			 _("ERROR: Redirection (%d) without location.\n"),
			 hstat.statcode);
	      xfree (filename_plus_orig_suffix); /* must precede every return! */
	      return WRONGCODE;
	    }
	  FREEHSTAT (hstat);
	  xfree (filename_plus_orig_suffix); /* must precede every return! */
	  return NEWLOCATION;
	  break;
	case RETRFINISHED:
