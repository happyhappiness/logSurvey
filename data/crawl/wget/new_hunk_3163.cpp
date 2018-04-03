	      logputs (LOG_NOTQUIET,
		       _("Write failed, closing control connection.\n"));
	      fd_close (csock);
	      con->csock = -1;
	      return err;
	      break;
	    case FTPNOPASV:
