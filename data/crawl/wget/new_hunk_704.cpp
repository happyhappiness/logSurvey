     the queue, but haven't been downloaded yet.  */
  struct hash_table *blacklist;

  queue = url_queue_new ();
  blacklist = make_string_hash_table (0);

