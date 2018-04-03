    {
      X509_STORE *store = SSL_CTX_get_cert_store (ssl_ctx);
      X509_LOOKUP *lookup;

      if (!(lookup = X509_STORE_add_lookup (store, X509_LOOKUP_file ()))
          || (!X509_load_crl_file (lookup, opt.crl_file, X509_FILETYPE_PEM)))
        goto error;

      X509_STORE_set_flags (store, X509_V_FLAG_CRL_CHECK | X509_V_FLAG_CRL_CHECK_ALL);
    }
