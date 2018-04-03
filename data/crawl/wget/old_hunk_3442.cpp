	  logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
		     proxy, url_error (up_error_code));
	  xfree (url);
	  return PROXERR;
	}
      if (proxy_url->scheme != SCHEME_HTTP && proxy_url->scheme != u->scheme)
