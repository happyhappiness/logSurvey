
  bool host_lookup_failed = false;

  DEBUGP(("in gethttp 1\n"));
  
#ifdef HAVE_SSL
  if (u->scheme == SCHEME_HTTPS)
    {
      /* Initialize the SSL context.  After this has once been done,
         it becomes a no-op.  */
      if (!ssl_init ())
        {
          scheme_disable (SCHEME_HTTPS);
          logprintf (LOG_NOTQUIET,
                     _("Disabling SSL due to encountered errors.\n"));
          return SSLINITFAILED;
        }
    }
#endif /* HAVE_SSL */

  DEBUGP(("in gethttp 2\n"));
  DEBUGP(("in gethttp 3\n"));
  
  /* Initialize certain elements of struct http_stat.  */
  hs->len = 0;
  hs->contlen = -1;
