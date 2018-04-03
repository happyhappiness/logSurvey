		? CONERROR : CONIMPOSSIBLE);

#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       {
	 if (!ssl_connect (sock))
	   {
	     logputs (LOG_VERBOSE, "\n");
	     logprintf (LOG_NOTQUIET,
			_("Unable to establish SSL connection.\n"));
	     fd_close (sock);
	     return CONSSLERR;
	   }
	 using_ssl = 1;
       }
#endif /* HAVE_SSL */
    }
  else
    {
      logprintf (LOG_VERBOSE, _("Reusing existing connection to %s:%d.\n"),
		 pconn.host, pconn.port);
      sock = pconn.socket;
      using_ssl = pconn.ssl;
      DEBUGP (("Reusing fd %d.\n", sock));
    }

  if (*dt & HEAD_ONLY)
    command = "HEAD";
