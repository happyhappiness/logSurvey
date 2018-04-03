ftp_do_port (struct rbuf *rbuf, int *local_sock)
{
  uerr_t err;
  int family;

  assert (rbuf != NULL);
  assert (rbuf_initialized_p (rbuf));

  family = getfamily (rbuf->fd);
  assert (family == AF_INET || family == AF_INET6);

  /* If our control connection is over IPv6, then we first try EPRT and then 
   * LPRT if the former is not supported. If the control connection is over 
   * IPv4, we simply issue the good old PORT request. */
  if (family == AF_INET6)
    {
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> EPRT ... ");
      err = ftp_eprt (rbuf, local_sock);
