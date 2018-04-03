    }
  else
    {
      logprintf (LOG_VERBOSE, _("Reusing connection to %s:%hu.\n"),
		 conn->host, conn->port);
      /* #### pc_last_fd should be accessed through an accessor
         function.  */
      sock = pconn.socket;
      using_ssl = pconn.ssl;
      DEBUGP (("Reusing fd %d.\n", sock));
