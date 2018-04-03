	  struct request *connreq = request_new ();
	  request_set_method (connreq, "CONNECT",
			      aprintf ("%s:%d", u->host, u->port));
	  if (proxyauth)
	    {
	      request_set_header (connreq, "Proxy-Authorization",
