
  int up_error_code;
  struct url *start_url_parsed;
  struct iri *i = iri_new ();
  set_uri_encoding (i, opt.locale);

  start_url_parsed = url_parse (start_url, &up_error_code, i);
  if (!start_url_parsed)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url,
