  else				/* cmd & DO_LOGIN */
    {
      char type_char;
      struct address_list *al;

      /* Login to the server: */

      /* First: Establish the control connection.  */

      al = lookup_host (u->host, 0);
      if (!al)
	return HOSTERR;
      set_connection_host_name (u->host);
      csock = connect_to_many (al, u->port, 0);
      set_connection_host_name (NULL);
      address_list_release (al);

      if (csock < 0)
	return errno == ECONNREFUSED ? CONREFUSED : CONERROR;

      if (cmd & LEAVE_PENDING)
	rbuf_initialize (&con->rbuf, csock);
      else
	rbuf_uninitialize (&con->rbuf);

      /* Since this is a new connection, we may safely discard
	 anything left in the buffer.  */
      rbuf_discard (&con->rbuf);

      /* Second: Login with proper USER/PASS sequence.  */
      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
      if (opt.server_response)
	logputs (LOG_ALWAYS, "\n");
