 	return (retryable_socket_connect_error (errno)
 		? CONERROR : CONIMPOSSIBLE);
 
-      if (cmd & LEAVE_PENDING)
-	rbuf_initialize (&con->rbuf, csock);
-      else
-	rbuf_uninitialize (&con->rbuf);
-
-      /* Since this is a new connection, we may safely discard
-	 anything left in the buffer.  */
-      rbuf_discard (&con->rbuf);
-
       /* Second: Login with proper USER/PASS sequence.  */
       logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
       if (opt.server_response)
 	logputs (LOG_ALWAYS, "\n");
-      err = ftp_login (&con->rbuf, logname, passwd);
+      err = ftp_login (csock, logname, passwd);
 
       if (con->proxy)
 	xfree (logname);
