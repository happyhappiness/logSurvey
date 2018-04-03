  SSL *ssl = (SSL *) fd_transport_context (fd);
  assert (ssl != NULL);

  peer_cert = SSL_get_peer_certificate (ssl);
  if (!peer_cert)
    {
      logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
		 severity, escnonprint (host));
      retval = 0;
      goto out;
    }

#ifdef ENABLE_DEBUG
  if (opt.debug)
    {
      char *subject = X509_NAME_oneline (X509_get_subject_name (peer_cert), 0, 0);
      char *issuer = X509_NAME_oneline (X509_get_issuer_name (peer_cert), 0, 0);
      DEBUGP (("certificate:\n  subject: %s\n  issuer:  %s\n",
	       escnonprint (subject), escnonprint (issuer)));
      OPENSSL_free (subject);
