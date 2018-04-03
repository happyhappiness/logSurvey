  head = fd_read_http_head (sock);
  if (!head)
    {
      logputs (LOG_VERBOSE, "\n");
      if (errno == 0)
	{
	  logputs (LOG_NOTQUIET, _("No data received.\n"));
	  CLOSE_INVALIDATE (sock);
	  return HEOF;
	}
      else
