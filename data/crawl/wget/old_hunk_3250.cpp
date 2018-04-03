  long post_data_size = 0;

#ifdef HAVE_SSL
  /* initialize ssl_ctx on first run */
  if (!ssl_ctx)
    {
      uerr_t err = init_ssl (&ssl_ctx);
      if (err != 0)
	{
	  switch (err)
	    {
	    case SSLERRCTXCREATE:
	      /* this is fatal */
	      logprintf (LOG_NOTQUIET, _("Failed to set up an SSL context\n"));
	      ssl_printerrors ();
	      return err;
	    case SSLERRCERTFILE:
	      /* try without certfile */
	      logprintf (LOG_NOTQUIET,
			 _("Failed to load certificates from %s\n"),
			 opt.sslcertfile);
	      ssl_printerrors ();
	      logprintf (LOG_NOTQUIET,
			 _("Trying without the specified certificate\n"));
	      break;
	    case SSLERRCERTKEY:
	      logprintf (LOG_NOTQUIET,
			 _("Failed to get certificate key from %s\n"),
			 opt.sslcertkey);
	      ssl_printerrors ();
	      logprintf (LOG_NOTQUIET,
			 _("Trying without the specified certificate\n"));
	      break;
	    default:
	      break;
	    }
	}
    }
#endif /* HAVE_SSL */

