	      if (dtsock < 0)
		{
		  int save_errno = errno;
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %hu: %s\n"),
			     pretty_print_address (&passive_addr), passive_port,
