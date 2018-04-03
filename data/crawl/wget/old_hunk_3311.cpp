	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  CLOSE (csock);
	  closeport (dtsock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
