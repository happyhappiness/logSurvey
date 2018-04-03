    }
  else
    {
      logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
		 pconn.host, pconn.port);
      sock = pconn.socket;
      using_ssl = pconn.ssl;
      DEBUGP (("Reusing fd %d.\n", sock));
