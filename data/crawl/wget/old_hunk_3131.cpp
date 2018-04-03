  int host_lookup_failed = 0;

#ifdef HAVE_SSL
  /* Initialize the SSL context.  After the first run, this is a
     no-op.  */
  switch (ssl_init ())
    {
    case SSLERRCTXCREATE:
      /* this is fatal */
      logprintf (LOG_NOTQUIET, _("Failed to set up an SSL context\n"));
      return SSLERRCTXCREATE;
    case SSLERRCERTFILE:
      /* try without certfile */
      logprintf (LOG_NOTQUIET,
		 _("Failed to load certificates from %s\n"),
		 opt.sslcertfile);
      logprintf (LOG_NOTQUIET,
		 _("Trying without the specified certificate\n"));
      break;
    case SSLERRCERTKEY:
      logprintf (LOG_NOTQUIET,
		 _("Failed to get certificate key from %s\n"),
		 opt.sslcertkey);
      logprintf (LOG_NOTQUIET,
		 _("Trying without the specified certificate\n"));
      break;
    default:
      break;
    }
#endif /* HAVE_SSL */

