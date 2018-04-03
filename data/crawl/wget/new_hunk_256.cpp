      goto out;
    }

  _CHECK_CERT (GNUTLS_CERT_INVALID, _("%s: The certificate of %s is not trusted.\n"));
  _CHECK_CERT (GNUTLS_CERT_SIGNER_NOT_FOUND, _("%s: The certificate of %s hasn't got a known issuer.\n"));
  _CHECK_CERT (GNUTLS_CERT_REVOKED, _("%s: The certificate of %s has been revoked.\n"));
  _CHECK_CERT (GNUTLS_CERT_SIGNER_NOT_CA, _("%s: The certificate signer of %s was not a CA.\n"));
  _CHECK_CERT (GNUTLS_CERT_INSECURE_ALGORITHM, _("%s: The certificate of %s was signed using an insecure algorithm.\n"));
  _CHECK_CERT (GNUTLS_CERT_NOT_ACTIVATED, _("%s: The certificate of %s is not yet activated.\n"));
  _CHECK_CERT (GNUTLS_CERT_EXPIRED, _("%s: The certificate of %s has expired.\n"));

  if (gnutls_certificate_type_get (ctx->session) == GNUTLS_CRT_X509)
    {
