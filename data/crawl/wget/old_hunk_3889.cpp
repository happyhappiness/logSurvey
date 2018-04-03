  FREE_MAYBE (proxyauth);

  /* Send the request to server.  */
  num_written = iwrite (sock, request, strlen (request));
  if (num_written < 0)
    {
      logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
		 strerror (errno));
      CLOSE_INVALIDATE (sock);
      return WRITEFAILED;
    }
  logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
