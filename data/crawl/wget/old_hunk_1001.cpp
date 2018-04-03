      proxy_url = url_parse (proxy, &up_error_code);
      if (!proxy_url)
        {
          logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
                     proxy, url_error (up_error_code));
          xfree (url);
          RESTORE_POST_DATA;
          return PROXERR;
        }