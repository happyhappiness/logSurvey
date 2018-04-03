#ifdef HAVE_SSL
     if (conn->scheme == SCHEME_HTTPS)
       {
	 if (!ssl_connect (sock))
	   {
	     logputs (LOG_VERBOSE, "\n");
	     logprintf (LOG_NOTQUIET,
