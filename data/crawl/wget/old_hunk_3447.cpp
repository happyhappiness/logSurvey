  uerr_t status = RETROK;

  /* The queue of URLs we need to load. */
  struct url_queue *queue = url_queue_new ();

  /* The URLs we do not wish to enqueue, because they are already in
     the queue, but haven't been downloaded yet.  */
  struct hash_table *blacklist = make_string_hash_table (0);

  /* We'll need various components of this, so better get it over with
     now. */
  struct url *start_url_parsed = url_parse (start_url, NULL);

  /* Enqueue the starting URL.  Use start_url_parsed->url rather than
     just URL so we enqueue the canonical form of the URL.  */
