	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
	      CLOSE (csock);
	      closeport (dtsock);
	      rbuf_uninitialize (&con->rbuf);
	      return err;
	      break;
