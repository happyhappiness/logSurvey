    request_set_header (req, "Proxy-Authorization", *proxyauth, rel_value);
}

/* Retrieve a document through HTTP protocol.  It recognizes status
   code, and correctly handles redirections.  It closes the network
   socket.  If it receives an error from the functions below it, it
   will print it if there is enough information to do so (almost
   always), returning the error to the caller (i.e. http_loop).

   Various HTTP parameters are stored to hs.

   If PROXY is non-NULL, the connection will be made to the proxy
   server, and u->url will be requested.  */
static uerr_t
gethttp (struct url *u, struct http_stat *hs, int *dt, struct url *proxy,
         struct iri *iri, int count)
{
  struct request *req;

  char *type;
  char *user, *passwd;
  char *proxyauth;
  int statcode;
  int write_error;
  wgint contlen, contrange;
  struct url *conn;
  FILE *fp;
  int err;

  int sock = -1;

  /* Set to 1 when the authorization has already been sent and should
     not be tried again. */
  bool auth_finished = false;

  /* Set to 1 when just globally-set Basic authorization has been sent;
   * should prevent further Basic negotiations, but not other
   * mechanisms. */
  bool basic_auth_finished = false;

  /* Whether NTLM authentication is used for this request. */
  bool ntlm_seen = false;

  /* Whether our connection to the remote host is through SSL.  */
  bool using_ssl = false;

  /* Whether a HEAD request will be issued (as opposed to GET or
     POST). */
  bool head_only = !!(*dt & HEAD_ONLY);

  char *head;
  struct response *resp;
  char hdrval[512];
  char *message;

  /* Declare WARC variables. */
  bool warc_enabled = (opt.warc_filename != NULL);
  FILE *warc_tmp = NULL;
  char warc_timestamp_str [21];
  char warc_request_uuid [48];
  ip_address *warc_ip = NULL;
  off_t warc_payload_offset = -1;

  /* Whether this connection will be kept alive after the HTTP request
     is done. */
  bool keep_alive;

  /* Is the server using the chunked transfer encoding?  */
  bool chunked_transfer_encoding = false;

  /* Whether keep-alive should be inhibited.  */
  bool inhibit_keep_alive =
    !opt.http_keep_alive || opt.ignore_length;

  /* Headers sent when using POST. */
  wgint body_data_size = 0;

  bool host_lookup_failed = false;

#ifdef HAVE_SSL
  if (u->scheme == SCHEME_HTTPS)
    {
      /* Initialize the SSL context.  After this has once been done,
         it becomes a no-op.  */
      if (!ssl_init ())
        {
          scheme_disable (SCHEME_HTTPS);
          logprintf (LOG_NOTQUIET,
                     _("Disabling SSL due to encountered errors.\n"));
          return SSLINITFAILED;
        }
    }
#endif /* HAVE_SSL */

  /* Initialize certain elements of struct http_stat.  */
  hs->len = 0;
  hs->contlen = -1;
  hs->res = -1;
  hs->rderrmsg = NULL;
  hs->newloc = NULL;
  xfree(hs->remote_time);
  hs->error = NULL;
  hs->message = NULL;

  conn = u;

  {
    uerr_t ret;
    req = initialize_request (u, hs, dt, proxy, inhibit_keep_alive,
                              &basic_auth_finished, &body_data_size,
                              &user, &passwd, &ret);
    if (req == NULL)
      return ret;
  }
 retry_with_auth:
  /* We need to come back here when the initial attempt to retrieve
     without authorization header fails.  (Expected to happen at least
     for the Digest authorization scheme.)  */

  if (opt.cookies)
    request_set_header (req, "Cookie",
                        cookie_header (wget_cookie_jar,
                                       u->host, u->port, u->path,
#ifdef HAVE_SSL
                                       u->scheme == SCHEME_HTTPS
#else
                                       0
#endif
                                       ),
                        rel_value);

  /* Add the user headers. */
  if (opt.user_headers)
    {
      int i;
      for (i = 0; opt.user_headers[i]; i++)
        request_set_user_header (req, opt.user_headers[i]);
    }

  proxyauth = NULL;
  if (proxy)
    {
      conn = proxy;
      initialize_proxy_configuration (u, req, proxy, &proxyauth);
    }
  keep_alive = true;

  /* Establish the connection.  */

  if (inhibit_keep_alive)
    keep_alive = false;
  else
    {
      /* Look for a persistent connection to target host, unless a
         proxy is used.  The exception is when SSL is in use, in which
