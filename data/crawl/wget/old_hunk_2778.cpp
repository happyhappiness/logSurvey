  vresult = SSL_get_verify_result (conn);
  if (vresult != X509_V_OK)
    {
      /* #### We might want to print saner (and translatable) error
	 messages for several frequently encountered errors.  The
	 candidates would include
	 X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY,
	 X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN,
	 X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT,
	 X509_V_ERR_CERT_NOT_YET_VALID, X509_V_ERR_CERT_HAS_EXPIRED,
	 and possibly others.  The current approach would still be
	 used for the less frequent failure cases.  */
      logprintf (LOG_NOTQUIET,
		 _("%s: Certificate verification error for %s: %s\n"),
		 severity, escnonprint (host),
		 X509_verify_cert_error_string (vresult));
      success = false;
      /* Fall through, so that the user is warned about *all* issues
	 with the cert (important with --no-check-certificate.)  */
