	  break;
	}
#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       if (connect_ssl (&ssl, ssl_ctx,sock) != 0)
	 {
	   logputs (LOG_VERBOSE, "\n");
