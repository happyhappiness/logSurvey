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
