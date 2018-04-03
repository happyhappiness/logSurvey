	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  fd_close (csock);
	  return err;
	  break;
	case FTPLOGREFUSED:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("The server refuses login.\n"));
	  fd_close (csock);
	  return FTPLOGREFUSED;
	  break;
	case FTPLOGINC:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("Login incorrect.\n"));
	  fd_close (csock);
	  return FTPLOGINC;
	  break;
	case FTPOK:
