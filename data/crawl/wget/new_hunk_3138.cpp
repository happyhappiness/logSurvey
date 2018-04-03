  head = fd_read_http_head (sock);
  if (!head)
    {
      if (errno == 0)
	{
	  logputs (LOG_NOTQUIET, _("No data received.\n"));
	  CLOSE_INVALIDATE (sock);
	  request_free (req);
	  return HEOF;
	}
      else
