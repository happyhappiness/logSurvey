  hs->remote_time = NULL;
  hs->error = NULL;

  /* If we're using a proxy, we will be connecting to the proxy
     server. */
  conn = proxy ? proxy : u;

  host_lookup_failed = 0;

  /* First: establish the connection.  */
  if (inhibit_keep_alive
      || !persistent_available_p (conn->host, conn->port,
#ifdef HAVE_SSL
				  u->scheme == SCHEME_HTTPS
#else
				  0
#endif
				  , &host_lookup_failed))
    {
      /* In its current implementation, persistent_available_p will
	 look up conn->host in some cases.  If that lookup failed, we
