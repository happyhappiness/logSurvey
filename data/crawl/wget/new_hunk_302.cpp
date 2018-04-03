      closedir (dir);
    }

  /* Use the private key from the cert file unless otherwise specified. */
  if (opt.cert_file && !opt.private_key)
    {
      opt.private_key = opt.cert_file;
      opt.private_key_type = opt.cert_type;
    }
  /* Use the cert from the private key file unless otherwise specified. */
  if (!opt.cert_file && opt.private_key)
    {
      opt.cert_file = opt.private_key;
      opt.cert_type = opt.private_key_type;
    }

  if (opt.cert_file && opt.private_key)
    {
      int type;
      if (opt.private_key_type != opt.cert_type)
	{
	  /* GnuTLS can't handle this */
	  logprintf (LOG_NOTQUIET, _("ERROR: GnuTLS requires the key and the \
cert to be of the same type.\n"));
	}

      type = key_type_to_gnutls_type (opt.private_key_type);

      gnutls_certificate_set_x509_key_file (credentials, opt.cert_file,
					    opt.private_key,
					    type);
    }

  if (opt.ca_cert)
    gnutls_certificate_set_x509_trust_file (credentials, opt.ca_cert,
                                            GNUTLS_X509_FMT_PEM);
