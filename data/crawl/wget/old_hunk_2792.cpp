  if (write_error < 0)
    {
      logprintf (LOG_VERBOSE, _("Failed writing HTTP request: %s.\n"),
		 strerror (errno));
      CLOSE_INVALIDATE (sock);
      request_free (req);
      return WRITEFAILED;
