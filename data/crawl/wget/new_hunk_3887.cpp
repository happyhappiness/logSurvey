
  /* First: establish the connection.  */
  if (inhibit_keep_alive
#ifndef HAVE_SSL
      || !persistent_available_p (u->host, u->port))
#else
      || !persistent_available_p (u->host, u->port, (u->proto==URLHTTPS ? 1 : 0)))
#endif /* HAVE_SSL */
    {
      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
      err = make_connection (&sock, u->host, u->port);
		switch (err)
	{
	case HOSTERR:
	  logputs (LOG_VERBOSE, "\n");
