# define FD_TO_SOCKET(X) (X)
#endif
  gnutls_transport_set_ptr (session, (gnutls_transport_ptr) FD_TO_SOCKET (fd));
  err = gnutls_handshake (session);
  if (err < 0)
    {
