 #endif /* HAVE_SSL */
       )
     {
-      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "),
-		 conn->host, conn->port);
-      err = make_connection (&sock, conn->host, conn->port);
-      switch (err)
-	{
-	case HOSTERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "%s: %s.\n", conn->host, herrmsg (h_errno));
-	  return HOSTERR;
-	  break;
-	case CONSOCKERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
-	  return CONSOCKERR;
-	  break;
-	case CONREFUSED:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET,
-		     _("Connection to %s:%hu refused.\n"), conn->host,
-		     conn->port);
-	  CLOSE (sock);
-	  return CONREFUSED;
-	case CONERROR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "connect: %s\n", strerror (errno));
-	  CLOSE (sock);
-	  return CONERROR;
-	  break;
-	case NOCONERROR:
-	  /* Everything is fine!  */
-	  logputs (LOG_VERBOSE, _("connected!\n"));
-	  break;
-	default:
-	  abort ();
-	  break;
-	}
+      struct address_list *al = lookup_host (conn->host, 0);
+      if (!al)
+	return HOSTERR;
+      set_connection_host_name (conn->host);
+      sock = connect_to_many (al, conn->port, 0);
+      set_connection_host_name (NULL);
+      address_list_release (al);
+
+      if (sock < 0)
+	return errno == ECONNREFUSED ? CONREFUSED : CONERROR;
+
 #ifdef HAVE_SSL
      if (conn->scheme == SCHEME_HTTPS)
        if (connect_ssl (&ssl, ssl_ctx,sock) != 0)
