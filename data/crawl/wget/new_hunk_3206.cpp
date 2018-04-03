		{
		  int save_errno = errno;
		  fd_close (csock);
		  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %hu: %s\n"),
			     pretty_print_address (&passive_addr), passive_port,
			     strerror (save_errno));
