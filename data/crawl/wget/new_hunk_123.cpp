
  ctx = xnew0 (struct openssl_transport_context);
  ctx->conn = conn;
  ctx->sess = SSL_get0_session (conn);
  if (!ctx->sess)
    logprintf (LOG_NOTQUIET, "WARNING: Could not save SSL session data for socket %d\n", fd);

  /* Register FD with Wget's transport layer, i.e. arrange that our
     functions are used for reading, writing, and polling.  */
