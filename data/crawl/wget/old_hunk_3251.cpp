#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       {
	 if (!connect_ssl (sock, ssl_ctx))
	   {
	     logputs (LOG_VERBOSE, "\n");
	     logprintf (LOG_NOTQUIET,
