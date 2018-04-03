
  /* First: establish the connection.  */
  if (inhibit_keep_alive
      || !persistent_available_p (u->host, u->port))
    {
      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
      err = make_connection (&sock, u->host, u->port);
      switch (err)
	{
	case HOSTERR:
	  logputs (LOG_VERBOSE, "\n");
