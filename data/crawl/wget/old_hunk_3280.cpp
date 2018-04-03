
#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       if (connect_ssl (&ssl, ssl_ctx,sock) != 0)
	 {
	   logputs (LOG_VERBOSE, "\n");
	   logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
	   ssl_printerrors ();
	   CLOSE (sock);
	   return CONSSLERR;
	 }
#endif /* HAVE_SSL */
    }
  else
