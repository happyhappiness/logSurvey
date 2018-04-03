  proxy = getproxy (u);
  if (proxy)
    {
      /* Parse the proxy URL.  */
      proxy_url = url_parse (proxy, &up_error_code);
      if (!proxy_url)
        {
          logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
