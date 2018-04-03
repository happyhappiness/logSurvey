	return (retryable_socket_connect_error (errno)
		? CONERROR : CONIMPOSSIBLE);

      /* Second: Login with proper USER/PASS sequence.  */
      logprintf (LOG_VERBOSE, _("Logging in as %s ... "), user);
      if (opt.server_response)
