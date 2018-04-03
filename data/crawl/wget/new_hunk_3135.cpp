	{
	  /* When requesting SSL URLs through proxies, use the
	     CONNECT method to request passthrough.  */
	  struct request *connreq = request_new ();
	  request_set_method (connreq, "CONNECT",
			      aprintf ("%s:%d", u->host, u->port));
	  if (proxyauth)
	    {
	      request_set_header (connreq, "Proxy-Authorization",
				  proxyauth, rel_value);
	      /* Now that PROXYAUTH is part of the CONNECT request,
		 zero it out so we don't send proxy authorization with
		 the regular request below.  */
	      proxyauth = NULL;
	    }

	  write_error = request_send (connreq, sock);
	  request_free (connreq);
	  if (write_error < 0)
	    {
	      logprintf (LOG_VERBOSE, _("Failed writing to proxy: %s.\n"),
