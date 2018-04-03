    {
      /* Initialize the SSL context.  After this has once been done,
	 it becomes a no-op.  */
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
		     opt.cert_file);
	  logprintf (LOG_NOTQUIET,
		     _("Trying without the specified certificate\n"));
	  break;
	case SSLERRCERTKEY:
	  logprintf (LOG_NOTQUIET,
		     _("Failed to get private key from %s\n"),
		     opt.private_key);
	  logprintf (LOG_NOTQUIET,
		     _("Trying without the specified certificate\n"));
	  break;
	default:
	  break;
	}
    }
#endif /* HAVE_SSL */
