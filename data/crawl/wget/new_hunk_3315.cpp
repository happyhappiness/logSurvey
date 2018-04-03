	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  CLOSE (csock);
	  CLOSE (dtsock);
	  CLOSE (local_sock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
