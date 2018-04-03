	      logputs (LOG_VERBOSE, "\n");
	      logputs (LOG_NOTQUIET, _("Invalid PORT.\n"));
	      fd_close (csock);
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return err;
