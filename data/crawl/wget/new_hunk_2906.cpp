      ssl_print_errors ();
      return SSLERRCTXCREATE;
    }

  SSL_CTX_set_default_verify_paths (ssl_ctx);
  SSL_CTX_load_verify_locations (ssl_ctx, opt.ca_cert, opt.ca_directory);
  SSL_CTX_set_verify (ssl_ctx,
		      opt.check_cert ? SSL_VERIFY_PEER : SSL_VERIFY_NONE,
		      verify_callback);

  if (opt.cert_file != NULL || opt.cert_key != NULL)
    {
      int ssl_cert_type;
      switch (opt.cert_type)
	{
	case cert_type_pem:
	  ssl_cert_type = SSL_FILETYPE_PEM;
	  break;
	case cert_type_asn1:
	  ssl_cert_type = SSL_FILETYPE_ASN1;
	  break;
	}

#if 0 /* what was this supposed to achieve? */
      if (opt.cert_key == NULL) 
	opt.cert_key = opt.cert_file;
      if (opt.cert_file == NULL)
	opt.cert_file = opt.cert_key;
#endif

      if (SSL_CTX_use_certificate_file (ssl_ctx, opt.cert_file,
					ssl_cert_type) != 1)
	{
	  ssl_print_errors ();
  	  return SSLERRCERTFILE;
	}
      if (SSL_CTX_use_PrivateKey_file (ssl_ctx, opt.cert_key,
				       ssl_cert_type) != 1)
	{
	  ssl_print_errors ();
	  return SSLERRCERTKEY;
