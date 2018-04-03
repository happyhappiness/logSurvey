	      logputs (LOG_NOTQUIET,
		       _("Write failed, closing control connection.\n"));
	      fd_close (csock);
	      fd_close (dtsock);
	      fd_close (local_sock);
	      return err;
