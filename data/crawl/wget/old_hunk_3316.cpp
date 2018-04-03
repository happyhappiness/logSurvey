	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("No such file or directory `%s'.\n\n"),
		     ".");
	  closeport (dtsock);
	  return err;
	  break;
	case FTPOK:
