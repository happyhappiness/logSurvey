  proxy = getproxy (u);
  if (proxy)
    {
      /* sXXXav : support IRI for proxy */
      bool proxy_utf8_encode = false;
      /* Parse the proxy URL.  */
      proxy_url = url_parse (proxy, &up_error_code, &proxy_utf8_encode);
      if (!proxy_url)
        {
          logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
