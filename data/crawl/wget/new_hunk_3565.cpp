  hs->remote_time = NULL;
  hs->error = NULL;

  /* If we're using a proxy, we will be connecting to the proxy
     server. */
  conn = proxy ? proxy : u;

  /* First: establish the connection.  */
  if (inhibit_keep_alive
      ||
#ifndef HAVE_SSL
      !persistent_available_p (conn->host, conn->port)
#else
      !persistent_available_p (conn->host, conn->port,
			       u->scheme == SCHEME_HTTPS)
#endif /* HAVE_SSL */
      )
    {
      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "),
		 conn->host, conn->port);
      err = make_connection (&sock, conn->host, conn->port);
      switch (err)
	{
	case HOSTERR:
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, "%s: %s.\n", conn->host, herrmsg (h_errno));
	  return HOSTERR;
	  break;
	case CONSOCKERR:
