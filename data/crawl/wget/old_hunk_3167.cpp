	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
	      fd_close (csock);
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return err;
