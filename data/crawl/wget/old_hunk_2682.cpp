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
	{
	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
		     fd_errstr (sock));
	  CLOSE_INVALIDATE (sock);
	  request_free (req);
	  return HERR;
	}
    }
  DEBUGP (("\n---response begin---\n%s---response end---\n", head));

