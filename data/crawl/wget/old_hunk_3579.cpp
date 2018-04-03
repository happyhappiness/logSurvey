  if (file)
    *file = NULL;

  u = newurl ();
  /* Parse the URL. */
  result = parseurl (url, u, 0);
  if (result != URLOK)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
      freeurl (u, 1);
      if (redirections)
	string_set_free (redirections);
      xfree (url);
      return result;
    }

 redirected:

  /* Set the referer.  */
  if (refurl)
    u->referer = xstrdup (refurl);
  else
    {
      if (opt.referer)
	u->referer = xstrdup (opt.referer);
      else
	u->referer = NULL;
    }

  local_use_proxy = USE_PROXY_P (u);
  if (local_use_proxy)
    {
      struct urlinfo *pu = newurl ();

      /* Copy the original URL to new location.  */
      memcpy (pu, u, sizeof (*u));
      pu->proxy = NULL; /* A minor correction :) */
      /* Initialize u to nil.  */
      memset (u, 0, sizeof (*u));
      u->proxy = pu;
      /* Get the appropriate proxy server, appropriate for the
	 current scheme.  */
      proxy = getproxy (pu->scheme);
      if (!proxy)
	{
	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}
      /* Parse the proxy URL.  */
      result = parseurl (proxy, u, 0);
      if (result != URLOK || u->scheme != SCHEME_HTTP)
	{
	  if (u->scheme == SCHEME_HTTP)
	    logprintf (LOG_NOTQUIET, "Proxy %s: %s.\n", proxy, uerrmsg(result));
	  else
	    logprintf (LOG_NOTQUIET, _("Proxy %s: Must be HTTP.\n"), proxy);
	  freeurl (u, 1);
	  if (redirections)
	    string_set_free (redirections);
	  xfree (url);
	  return PROXERR;
	}
      u->scheme = SCHEME_HTTP;
    }

  mynewloc = NULL;

  if (u->scheme == SCHEME_HTTP
#ifdef HAVE_SSL
      || u->scheme == SCHEME_HTTPS
#endif
      )
    result = http_loop (u, &mynewloc, dt);
  else if (u->scheme == SCHEME_FTP)
    {
      /* If this is a redirection, we must not allow recursive FTP
