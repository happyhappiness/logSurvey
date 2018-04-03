
  ctx = xnew0 (struct openssl_transport_context);
  ctx->conn = conn;

  /* Register FD with Wget's transport layer, i.e. arrange that our
     functions are used for reading, writing, and polling.  */
