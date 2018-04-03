     the queue, but haven't been downloaded yet.  */
  struct hash_table *blacklist;

  int up_error_code;
  struct url *start_url_parsed = url_parse (start_url, &up_error_code);

  if (!start_url_parsed)
    {
      char *error = url_error (start_url, up_error_code);
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url, error);
      xfree (error);
      return URLERROR;
    }

  queue = url_queue_new ();
  blacklist = make_string_hash_table (0);

