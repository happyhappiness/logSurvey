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
