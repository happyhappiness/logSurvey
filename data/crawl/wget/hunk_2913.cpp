 	  struct request *connreq = request_new ();
 	  request_set_method (connreq, "CONNECT",
 			      aprintf ("%s:%d", u->host, u->port));
+	  SET_USER_AGENT (req);
 	  if (proxyauth)
 	    {
 	      request_set_header (connreq, "Proxy-Authorization",
