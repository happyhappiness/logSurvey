   else				/* cmd & DO_LOGIN */
     {
       char type_char;
+      struct address_list *al;
 
       /* Login to the server: */
 
       /* First: Establish the control connection.  */
-      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
-      err = make_connection (&csock, u->host, u->port);
+
+      al = lookup_host (u->host, 0);
+      if (!al)
+	return HOSTERR;
+      set_connection_host_name (u->host);
+      csock = connect_to_many (al, u->port, 0);
+      set_connection_host_name (NULL);
+      address_list_release (al);
+
+      if (csock < 0)
+	return errno == ECONNREFUSED ? CONREFUSED : CONERROR;
+
       if (cmd & LEAVE_PENDING)
 	rbuf_initialize (&con->rbuf, csock);
       else
 	rbuf_uninitialize (&con->rbuf);
-      switch (err)
-	{
-	  /* Do not close the socket in first several cases, since it
-	     wasn't created at all.  */
-	case HOSTERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "%s: %s\n", u->host, herrmsg (h_errno));
-	  return HOSTERR;
-	  break;
-	case CONSOCKERR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
-	  return CONSOCKERR;
-	  break;
-	case CONREFUSED:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, _("Connection to %s:%hu refused.\n"),
-		     u->host, u->port);
-	  CLOSE (csock);
-	  rbuf_uninitialize (&con->rbuf);
-	  return CONREFUSED;
-	case CONERROR:
-	  logputs (LOG_VERBOSE, "\n");
-	  logprintf (LOG_NOTQUIET, "connect: %s\n", strerror (errno));
-	  CLOSE (csock);
-	  rbuf_uninitialize (&con->rbuf);
-	  return CONERROR;
-	  break;
-	default:
-	  DO_NOTHING;
-	  /* #### Hmm?  */
-	}
+
       /* Since this is a new connection, we may safely discard
 	 anything left in the buffer.  */
       rbuf_discard (&con->rbuf);
 
       /* Second: Login with proper USER/PASS sequence.  */
-      logputs (LOG_VERBOSE, _("connected!\n"));
       logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
       if (opt.server_response)
 	logputs (LOG_ALWAYS, "\n");
