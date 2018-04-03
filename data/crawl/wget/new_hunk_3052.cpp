	  break;
	case FT_UNKNOWN:
	  logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
		     escnonprint (f->name));
	  break;
	}	/* switch */

