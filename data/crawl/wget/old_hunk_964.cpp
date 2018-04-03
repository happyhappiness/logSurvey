  struct hash_table *blacklist;

  int up_error_code;
  struct url *start_url_parsed = url_parse (start_url, &up_error_code, &utf8_encode);

  if (!start_url_parsed)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url,
