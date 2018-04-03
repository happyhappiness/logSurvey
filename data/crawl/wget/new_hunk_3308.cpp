	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
	      CLOSE (csock);
	      CLOSE (dtsock);
	      CLOSE (local_sock);
	      rbuf_uninitialize (&con->rbuf);
	      return err;
	      break;
