  wgnutls_peek, wgnutls_errstr, wgnutls_close
};

bool
ssl_connect_wget (int fd, const char *hostname, int *continue_session)
{
#ifdef F_GETFL
  int flags = 0;
#endif
  struct wgnutls_transport_context *ctx;
  gnutls_session_t session;
  int err;
  const char *str;

  gnutls_init (&session, GNUTLS_CLIENT);

