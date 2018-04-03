
  if (!start_url_parsed)
    {
      char *error = url_error (start_url, up_error_code);
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url, error);
      xfree (error);
      return URLERROR;
    }

