  struct wgnutls_transport_context *ctx = fd_transport_context (fd);

  unsigned int status;
  const gnutls_datum *cert_list;
  int cert_list_size, ret;
  gnutls_x509_crt cert;

  /* If the user has specified --no-check-cert, we still want to warn
     him about problems with the server's certificate.  */
  const char *severity = opt.check_cert ? _("ERROR") : _("WARNING");
  bool success = true;

  ret = gnutls_certificate_verify_peers2 (ctx->session, &status);
  if (ret < 0)
    {
      logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
		 severity, escnonprint (host));
      success = false;
      goto no_cert;
    }

  if (status & GNUTLS_CERT_INVALID)
