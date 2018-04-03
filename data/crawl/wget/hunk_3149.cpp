 	return (retryable_socket_connect_error (errno)
 		? CONERROR : CONIMPOSSIBLE);
 
+      if (cmd & LEAVE_PENDING)
+	con->csock = csock;
+      else
+	con->csock = -1;
+
       /* Second: Login with proper USER/PASS sequence.  */
       logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
       if (opt.server_response)
