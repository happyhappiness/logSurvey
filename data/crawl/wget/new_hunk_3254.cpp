	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  xclose (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case FTPLOGREFUSED:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("The server refuses login.\n"));
	  xclose (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return FTPLOGREFUSED;
	  break;
	case FTPLOGINC:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("Login incorrect.\n"));
	  xclose (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return FTPLOGINC;
	  break;
