  statcode = -1;
  *dt &= ~RETROKF;

  head = fd_read_http_head (sock);
  if (!head)
    {
      logputs (LOG_VERBOSE, "\n");
