  uerr_t status = RETROK;

  /* The queue of URLs we need to load. */
  struct url_queue *queue;

  /* The URLs we do not wish to enqueue, because they are already in
     the queue, but haven't been downloaded yet.  */
  struct hash_table *blacklist;

  int up_error_code;
  struct url *start_url_parsed = url_parse (start_url, &up_error_code);

  if (!start_url_parsed)
    {
      logprintf (LOG_NOTQUIET, "%s: %s.\n", start_url,
		 url_error (up_error_code));
      return URLERROR;
    }

  queue = url_queue_new ();
  blacklist = make_string_hash_table (0);

  /* Enqueue the starting URL.  Use start_url_parsed->url rather than
     just URL so we enqueue the canonical form of the URL.  */
