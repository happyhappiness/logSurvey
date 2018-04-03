ftp_do_pasv (struct rbuf *rbuf, ip_address *addr, int *port)
{
  uerr_t err;
  int family;

  family = getfamily (rbuf->fd);
  assert (family == AF_INET || family == AF_INET6);

  /* If our control connection is over IPv6, then we first try EPSV and then 
   * LPSV if the former is not supported. If the control connection is over 
   * IPv4, we simply issue the good old PASV request. */
  if (family == AF_INET6)
    {
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> EPSV ... ");
      err = ftp_epsv (rbuf, addr, port);
