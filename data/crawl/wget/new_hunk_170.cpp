    request_set_header (req, "Proxy-Authorization", *proxyauth, rel_value);
}

static uerr_t
establish_connection (struct url *u, struct url **conn_ref,
                      struct http_stat *hs, struct url *proxy,
                      char **proxyauth,
                      struct request **req_ref, bool *using_ssl,
                      bool inhibit_keep_alive,
                      int *sock_ref)
{
  bool host_lookup_failed = false;
  int sock = *sock_ref;
  struct request *req = *req_ref;
  struct url *conn = *conn_ref;
  struct response *resp;
  int write_error;
  int statcode;

  if (! inhibit_keep_alive)
    {
      /* Look for a persistent connection to target host, unless a
         proxy is used.  The exception is when SSL is in use, in which
