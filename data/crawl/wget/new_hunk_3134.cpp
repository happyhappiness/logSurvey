      /* #### This does not appear right.  Can't the proxy request,
	 say, `Digest' authentication?  */
      if (proxy_user && proxy_passwd)
	proxyauth = basic_authentication_encode (proxy_user, proxy_passwd);

      /* If we're using a proxy, we will be connecting to the proxy
	 server.  */
      conn = proxy;
    }

  /* Prepare the request to send. */

  req = request_new ();
  {
    const char *meth = "GET";
    if (*dt & HEAD_ONLY)
      meth = "HEAD";
    else if (opt.post_file_name || opt.post_data)
      meth = "POST";
    /* Use the full path, i.e. one that includes the leading slash and
       the query string.  E.g. if u->path is "foo/bar" and u->query is
       "param=value", full_path will be "/foo/bar?param=value".  */
    request_set_method (req, meth,
			proxy ? xstrdup (u->url) : url_full_path (u));
  }

  request_set_header (req, "Referer", (char *) hs->referer, rel_none);
  if (*dt & SEND_NOCACHE)
    request_set_header (req, "Pragma", "no-cache", rel_none);
  if (hs->restval)
    request_set_header (req, "Range",
			aprintf ("bytes=%ld-", hs->restval), rel_value);
  if (opt.useragent)
    request_set_header (req, "User-Agent", opt.useragent, rel_none);
  else
    request_set_header (req, "User-Agent",
			aprintf ("Wget/%s", version_string), rel_value);
  request_set_header (req, "Accept", "*/*", rel_none);

  /* Find the username and password for authentication. */
  user = u->user;
  passwd = u->passwd;
  search_netrc (u->host, (const char **)&user, (const char **)&passwd, 0);
  user = user ? user : opt.http_user;
  passwd = passwd ? passwd : opt.http_passwd;

  if (user && passwd)
    {
      /* We have the username and the password, but haven't tried
	 any authorization yet.  Let's see if the "Basic" method
	 works.  If not, we'll come back here and construct a
	 proper authorization method with the right challenges.

	 If we didn't employ this kind of logic, every URL that
	 requires authorization would have to be processed twice,
	 which is very suboptimal and generates a bunch of false
	 "unauthorized" errors in the server log.

	 #### But this logic also has a serious problem when used
	 with stronger authentications: we *first* transmit the
	 username and the password in clear text, and *then* attempt a
	 stronger authentication scheme.  That cannot be right!  We
	 are only fortunate that almost everyone still uses the
	 `Basic' scheme anyway.

	 There should be an option to prevent this from happening, for
	 those who use strong authentication schemes and value their
	 passwords.  */
      request_set_header (req, "Authorization",
			  basic_authentication_encode (user, passwd),
			  rel_value);
    }

  {
    /* Whether we need to print the host header with braces around
       host, e.g. "Host: [3ffe:8100:200:2::2]:1234" instead of the
       usual "Host: symbolic-name:1234". */
    int squares = strchr (u->host, ':') != NULL;
    if (u->port == scheme_default_port (u->scheme))
      request_set_header (req, "Host",
			  aprintf (squares ? "[%s]" : "%s", u->host),
			  rel_value);
    else
      request_set_header (req, "Host",
			  aprintf (squares ? "[%s]:%d" : "%s:%d",
				   u->host, u->port),
			  rel_value);
  }

  if (!inhibit_keep_alive)
    request_set_header (req, "Connection", "Keep-Alive", rel_none);

  if (opt.cookies)
    request_set_header (req, "Cookie",
			cookie_header (wget_cookie_jar,
				       u->host, u->port, u->path,
#ifdef HAVE_SSL
				       u->scheme == SCHEME_HTTPS
#else
				       0
#endif
				       ),
			rel_value);

  if (opt.post_data || opt.post_file_name)
    {
      request_set_header (req, "Content-Type",
			  "application/x-www-form-urlencoded", rel_none);
      if (opt.post_data)
	post_data_size = strlen (opt.post_data);
      else
	{
	  post_data_size = file_size (opt.post_file_name);
	  if (post_data_size == -1)
	    {
	      logprintf (LOG_NOTQUIET, "POST data file missing: %s\n",
			 opt.post_file_name);
	      post_data_size = 0;
	    }
	}
      request_set_header (req, "Content-Length",
			  aprintf ("Content-Length: %ld", post_data_size),
			  rel_value);
    }

  /* Add the user headers. */
  if (opt.user_headers)
    {
      int i;
      for (i = 0; opt.user_headers[i]; i++)
	request_set_user_header (req, opt.user_headers[i]);
    }

 retry_with_auth:
  /* We need to come back here when the initial attempt to retrieve
     without authorization header fails.  (Expected to happen at least
     for the Digest authorization scheme.)  */

  keep_alive = 0;
  keep_alive_confirmed = 0;

  /* Establish the connection.  */

  if (!inhibit_keep_alive)
    {
