#else

static uerr_t
ftp_do_pasv (struct rbuf *rbuf, ip_address *addr, int *port)
{
  if (!opt.server_response)
    logputs (LOG_VERBOSE, "==> PASV ... ");
  return ftp_pasv (rbuf, addr, port);
}

static uerr_t
ftp_do_port (struct rbuf *rbuf, int *local_sock)
{
  if (!opt.server_response)
    logputs (LOG_VERBOSE, "==> PORT ... ");
  return ftp_port (rbuf, local_sock);
}
#endif

