  SSL *ssl = (SSL *) fd_transport_context (fd);
  assert (ssl != NULL);

  cert = SSL_get_peer_certificate (ssl);
  if (!cert)
    {
      logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
		 severity, escnonprint (host));
      success = 0;
      goto out;
    }

#ifdef ENABLE_DEBUG
  if (opt.debug)
    {
      char *subject = X509_NAME_oneline (X509_get_subject_name (cert), 0, 0);
      char *issuer = X509_NAME_oneline (X509_get_issuer_name (cert), 0, 0);
      DEBUGP (("certificate:\n  subject: %s\n  issuer:  %s\n",
	       escnonprint (subject), escnonprint (issuer)));
      OPENSSL_free (subject);
