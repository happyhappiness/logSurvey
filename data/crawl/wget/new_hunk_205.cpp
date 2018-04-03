  SSL_CTX_set_default_verify_paths (ssl_ctx);
  SSL_CTX_load_verify_locations (ssl_ctx, opt.ca_cert, opt.ca_directory);

  if (opt.crl_file)
    {
      X509_STORE *store = SSL_CTX_get_cert_store (ssl_ctx);
      X509_LOOKUP *lookup;
      int rc;

      if (!(lookup = X509_STORE_add_lookup (store, X509_LOOKUP_file ()))
          || (!(rc = X509_load_crl_file (lookup, opt.crl_file, X509_FILETYPE_PEM))))
        {
          logprintf (LOG_NOTQUIET, _("ERROR: Failed to load CRL file '%s': (%d)\n"), opt.crl_file, rc);
          return false;
        }

      X509_STORE_set_flags (store, X509_V_FLAG_CRL_CHECK | X509_V_FLAG_CRL_CHECK_ALL);
    }

  /* SSL_VERIFY_NONE instructs OpenSSL not to abort SSL_connect if the
     certificate is invalid.  We verify the certificate separately in
     ssl_check_certificate, which provides much better diagnostics
