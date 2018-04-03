 		{
 		  int save_errno = errno;
 		  fd_close (csock);
-		  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %hu: %s\n"),
+		  con->csock = -1;
+		  logprintf (LOG_VERBOSE, _("couldn't connect to %s port %d: %s\n"),
 			     pretty_print_address (&passive_addr), passive_port,
 			     strerror (save_errno));
 		  return (retryable_socket_connect_error (save_errno)
