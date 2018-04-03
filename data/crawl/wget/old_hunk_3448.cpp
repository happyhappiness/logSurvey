  if (!u)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, url_error (up_error_code));
      if (redirections)
	string_set_free (redirections);
      xfree (url);
      return URLERROR;
    }
