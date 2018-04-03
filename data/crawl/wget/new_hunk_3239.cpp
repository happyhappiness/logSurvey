ftp_do_pasv (struct rbuf *rbuf, ip_address *addr, int *port)
{
  uerr_t err;

  /* We need to determine the address family and need to call
     getpeername, so while we're at it, store the address to ADDR.
     ftp_pasv and ftp_lpsv can simply override it.  */
  if (!socket_ip_address (RBUF_FD (rbuf), addr, ENDPOINT_PEER))
    abort ();

  /* If our control connection is over IPv6, then we first try EPSV and then 
   * LPSV if the former is not supported. If the control connection is over 
   * IPv4, we simply issue the good old PASV request. */
  switch (addr->type)
    {
    case IPV4_ADDRESS:
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> PASV ... ");
      err = ftp_pasv (rbuf, addr, port);
      break;
    case IPV6_ADDRESS:
      if (!opt.server_response)
        logputs (LOG_VERBOSE, "==> EPSV ... ");
      err = ftp_epsv (rbuf, addr, port);
