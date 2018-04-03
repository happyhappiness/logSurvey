 	{
 	  /* When requesting SSL URLs through proxies, use the
 	     CONNECT method to request passthrough.  */
-	  char *connect =
-	    (char *) alloca (64
-			     + strlen (u->host)
-			     + (proxyauth ? strlen (proxyauth) : 0));
-	  sprintf (connect, "CONNECT %s:%d HTTP/1.0\r\n%s\r\n",
-		   u->host, u->port, proxyauth ? proxyauth : "");
-	  /* Now that PROXYAUTH is part of the CONNECT request, zero
-	     it out so we don't send proxy authorization with the
-	     regular request below.  */
-	  proxyauth = NULL;
-
-	  DEBUGP (("Writing to proxy: [%s]\n", connect));
-	  write_error = fd_write (sock, connect, strlen (connect), -1);
+	  struct request *connreq = request_new ();
+	  request_set_method (connreq, "CONNECT",
+			      aprintf ("%s:%d", u->host, u->port));
+	  if (proxyauth)
+	    {
+	      request_set_header (connreq, "Proxy-Authorization",
+				  proxyauth, rel_value);
+	      /* Now that PROXYAUTH is part of the CONNECT request,
+		 zero it out so we don't send proxy authorization with
+		 the regular request below.  */
+	      proxyauth = NULL;
+	    }
+
+	  write_error = request_send (connreq, sock);
+	  request_free (connreq);
 	  if (write_error < 0)
 	    {
 	      logprintf (LOG_VERBOSE, _("Failed writing to proxy: %s.\n"),
