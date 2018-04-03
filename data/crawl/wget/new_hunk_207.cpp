        }
    }

  if (opt.ca_cert)
    {
      int rc;

      ncerts = 0;

      if ((rc = gnutls_certificate_set_x509_trust_file (credentials, opt.ca_cert,
                                                        GNUTLS_X509_FMT_PEM)) <= 0)
        logprintf (LOG_NOTQUIET, _ ("ERROR: Failed to open cert %s: (%d).\n"),
                   opt.ca_cert, rc);
      else
        {
          ncerts += rc;
          logprintf (LOG_NOTQUIET, _ ("Loaded CA certificate '%s'\n"), opt.ca_cert);
        }
    }

  if (opt.crl_file)
    {
      int rc;

      if ((rc = gnutls_certificate_set_x509_crl_file (credentials, opt.crl_file, GNUTLS_X509_FMT_PEM)) <= 0)
        {
          logprintf (LOG_NOTQUIET, _("ERROR: Failed to load CRL file '%s': (%d)\n"), opt.crl_file, rc);
          return false;
        }

      logprintf (LOG_NOTQUIET, _ ("Loaded CRL file '%s'\n"), opt.crl_file);
    }

  DEBUGP (("Certificates loaded: %d\n", ncerts));

  /* Use the private key from the cert file unless otherwise specified. */
