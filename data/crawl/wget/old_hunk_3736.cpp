  int inhibit_keep_alive;

#ifdef HAVE_SSL
/* initialize ssl_ctx on first run */
  if (!ssl_ctx)
    init_ssl (&ssl_ctx);
#endif /* HAVE_SSL */

  if (!(*dt & HEAD_ONLY))
