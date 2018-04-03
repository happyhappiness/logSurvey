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
