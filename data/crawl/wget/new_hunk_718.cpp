  
  if (url_has_scheme (url))
    {
      int dt,url_err;
      uerr_t status;
      struct url * url_parsed = url_parse(url, &url_err);

      if (!url_parsed)
        {
          char *error = url_error (url, url_err);
          logprintf (LOG_NOTQUIET, "%s: %s.\n", url, error);
          xfree (error);
          return URLERROR;
        }

      if (!opt.base_href)
        opt.base_href = xstrdup (url);

      status = retrieve_url (url_parsed, url, &input_file, NULL, NULL, &dt, false);
      if (status != RETROK)
        return status;

