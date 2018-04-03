	      closeport (dtsock);
	      return err;
	      break;
	    case HOSTERR:
	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, "%s: %s\n", u->host,
			 herrmsg (h_errno));
	      CLOSE (csock);
	      closeport (dtsock);
	      rbuf_uninitialize (&con->rbuf);
	      return HOSTERR;
	      break;
	    case FTPPORTERR:
	      logputs (LOG_VERBOSE, "\n");
	      logputs (LOG_NOTQUIET, _("Invalid PORT.\n"));
