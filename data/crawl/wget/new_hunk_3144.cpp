  hs->remote_time = NULL;
  hs->error = NULL;

  conn = u;

  proxyauth = NULL;
  if (proxy)
    {
      char *proxy_user, *proxy_passwd;
      /* For normal username and password, URL components override
	 command-line/wgetrc parameters.  With proxy
	 authentication, it's the reverse, because proxy URLs are
	 normally the "permanent" ones, so command-line args
	 should take precedence.  */
      if (opt.proxy_user && opt.proxy_passwd)
	{
	  proxy_user = opt.proxy_user;
	  proxy_passwd = opt.proxy_passwd;
	}
      else
	{
	  proxy_user = proxy->user;
	  proxy_passwd = proxy->passwd;
	}
      /* #### This does not appear right.  Can't the proxy request,
	 say, `Digest' authentication?  */
      if (proxy_user && proxy_passwd)
	proxyauth = basic_authentication_encode (proxy_user, proxy_passwd,
						 "Proxy-Authorization");

      /* If we're using a proxy, we will be connecting to the proxy
	 server.  */
      conn = proxy;
    }

  host_lookup_failed = 0;
  sock = -1;

  /* First: establish the connection.  */

  if (!inhibit_keep_alive)
    {
      /* Look for a persistent connection to target host, unless a
	 proxy is used.  The exception is when SSL is in use, in which
	 case the proxy is nothing but a passthrough to the target
	 host, registered as a connection to the latter.  */
      struct url *relevant = conn;
#ifdef HAVE_SSL
      if (u->scheme == SCHEME_HTTPS)
	relevant = u;
#endif

      if (persistent_available_p (relevant->host, relevant->port,
#ifdef HAVE_SSL
				  relevant->scheme == SCHEME_HTTPS,
#else
				  0,
#endif
				  &host_lookup_failed))
	{
	  sock = pconn.socket;
	  using_ssl = pconn.ssl;
	  logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
		     pconn.host, pconn.port);
	  DEBUGP (("Reusing fd %d.\n", sock));
	}
    }

  if (sock < 0)
    {
      /* In its current implementation, persistent_available_p will
	 look up conn->host in some cases.  If that lookup failed, we
