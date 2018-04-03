	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, _("Bind error (%s).\n"),
			 strerror (errno));
	      CLOSE (dtsock);
	      CLOSE (local_sock);
	      return err;
	      break;
	    case FTPPORTERR:
	      logputs (LOG_VERBOSE, "\n");
	      logputs (LOG_NOTQUIET, _("Invalid PORT.\n"));
	      CLOSE (csock);
	      CLOSE (dtsock);
	      CLOSE (local_sock);
	      rbuf_uninitialize (&con->rbuf);
	      return err;
	      break;
