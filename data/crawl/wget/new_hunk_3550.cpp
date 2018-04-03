	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET,
		     _("Unknown type `%c', closing control connection.\n"),
		     type_char);
	  CLOSE (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
