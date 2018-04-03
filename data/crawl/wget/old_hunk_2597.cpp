  if (!start_url_parsed)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url,
		 url_error (up_error_code));
      return URLERROR;
    }

