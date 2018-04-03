    {
      char *issuer = X509_NAME_oneline (X509_get_issuer_name (cert), 0, 0);
      logprintf (LOG_NOTQUIET,
                 _("%s: cannot verify %s's certificate, issued by `%s':\n"),
                 severity, escnonprint (host), escnonprint (issuer));
      /* Try to print more user-friendly (and translated) messages for
         the frequent verification errors.  */
      switch (vresult)
        {
        case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
          logprintf (LOG_NOTQUIET,
                     _("  Unable to locally verify the issuer's authority.\n"));
          break;
        case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
        case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
          logprintf (LOG_NOTQUIET, _("  Self-signed certificate encountered.\n"));
          break;
        case X509_V_ERR_CERT_NOT_YET_VALID:
          logprintf (LOG_NOTQUIET, _("  Issued certificate not yet valid.\n"));
          break;
        case X509_V_ERR_CERT_HAS_EXPIRED:
          logprintf (LOG_NOTQUIET, _("  Issued certificate has expired.\n"));
          break;
        default:
          /* For the less frequent error strings, simply provide the
             OpenSSL error message.  */
          logprintf (LOG_NOTQUIET, "  %s\n",
                     X509_verify_cert_error_string (vresult));
        }
      success = false;
      /* Fall through, so that the user is warned about *all* issues
         with the cert (important with --no-check-certificate.)  */
    }

  /* Check that HOST matches the common name in the certificate.
