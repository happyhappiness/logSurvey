  /* Send the request to server.  */
#ifdef HAVE_SSL
  if (conn->scheme == SCHEME_HTTPS)
    num_written = ssl_iwrite (ssl, request, strlen (request));
  else
#endif /* HAVE_SSL */
    num_written = iwrite (sock, request, strlen (request));

  if (num_written < 0)
    {
      logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
		 strerror (errno));
