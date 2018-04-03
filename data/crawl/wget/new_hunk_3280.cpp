
#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       {
	 if (!connect_ssl (sock, ssl_ctx))
	   {
	     logputs (LOG_VERBOSE, "\n");
	     logprintf (LOG_NOTQUIET,
			_("Unable to establish SSL connection.\n"));
	     xclose (sock);
	     return CONSSLERR;
	   }
	 using_ssl = 1;
       }
#endif /* HAVE_SSL */
    }
  else
