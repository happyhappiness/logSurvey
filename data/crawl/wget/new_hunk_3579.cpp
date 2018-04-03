  if (file)
    *file = NULL;

  u = url_parse (url, &up_error_code);
  if (!u)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, url_error (up_error_code));
      if (redirections)
	string_set_free (redirections);
      xfree (url);
      return URLERROR;
    }

  if (!refurl)
    refurl = opt.referer;

 redirected:

  result = NOCONERROR;
  mynewloc = NULL;
  local_file = NULL;

  use_proxy = USE_PROXY_P (u);
  if (use_proxy)
    {
      struct url *proxy_url;

      /* Get the proxy server for the current scheme.  */
      proxy = getproxy (u->scheme);
      if (!proxy)
	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  url_free (u);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}

      /* Parse the proxy URL.  */
      proxy_url = url_parse (proxy, &up_error_code);
      if (!proxy_url)
	{
	  logprintf (LOG_NOTQUIET, "Error parsing proxy URL %s: %s.\n",
		     proxy, url_error (up_error_code));
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}
      if (proxy_url->scheme != SCHEME_HTTP)
	{
	  logprintf (LOG_NOTQUIET, _("Error in proxy URL %s: Must be HTTP.\n"), proxy);
	  url_free (proxy_url);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}

      result = http_loop (u, &mynewloc, &local_file, refurl, dt, proxy_url);
      url_free (proxy_url);
    }
  else if (u->scheme == SCHEME_HTTP
#ifdef HAVE_SSL
      || u->scheme == SCHEME_HTTPS
#endif
      )
    {
      result = http_loop (u, &mynewloc, &local_file, refurl, dt, NULL);
    }
  else if (u->scheme == SCHEME_FTP)
    {
      /* If this is a redirection, we must not allow recursive FTP
