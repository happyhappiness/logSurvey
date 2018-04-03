  proxy = getproxy (u);
  if (proxy)
    {
      /* sXXXav : support IRI for proxy */
      /* Parse the proxy URL.  */
      set_ugly_no_encode (true);
      proxy_url = url_parse (proxy, &up_error_code);
      set_ugly_no_encode (false);
      if (!proxy_url)
        {
          logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
