  hs->remote_time = NULL;
  hs->error = NULL;

  /* Which structure to use to retrieve the original URL data.  */
  if (u->proxy)
    ou = u->proxy;
  else
    ou = u;

  /* First: establish the connection.  */
  if (inhibit_keep_alive
      ||
#ifndef HAVE_SSL
      !persistent_available_p (u->host, u->port)
#else
      !persistent_available_p (u->host, u->port, u->scheme == SCHEME_HTTPS)
#endif /* HAVE_SSL */
      )
    {
      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
      err = make_connection (&sock, u->host, u->port);
      switch (err)
	{
	case HOSTERR:
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", u->host, herrmsg (h_errno));
	  return HOSTERR;
	  break;
	case CONSOCKERR:
