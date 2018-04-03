  
  if (url_has_scheme (url))
    {
      int dt;
      uerr_t status;

      if (!opt.base_href)
        opt.base_href = xstrdup (url);

      status = retrieve_url (url, &input_file, NULL, NULL, &dt, false);
      if (status != RETROK)
        return status;

