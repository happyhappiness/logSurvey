  vresult = SSL_get_verify_result (ssl);
  if (vresult != X509_V_OK)
    {
      logprintf (LOG_NOTQUIET,
		 _("%s: Certificate verification error for %s: %s\n"),
		 severity, escnonprint (host),
		 X509_verify_cert_error_string (vresult));
      success = 0;
      goto out;
    }

  /* Check that HOST matches the common name in the certificate.
