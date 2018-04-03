	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("No such file or directory `%s'.\n\n"),
		     ".");
	  xclose (dtsock);
	  xclose (local_sock);
	  return err;
	  break;
	case FTPOK:
