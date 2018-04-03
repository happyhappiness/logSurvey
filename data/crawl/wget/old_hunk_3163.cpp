	      logputs (LOG_NOTQUIET,
		       _("Write failed, closing control connection.\n"));
	      fd_close (csock);
	      return err;
	      break;
	    case FTPNOPASV:
