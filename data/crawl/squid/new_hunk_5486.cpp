	debug(83, 5) ("Using chiper suite %s.\n", cipher);
	if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
	    ssl_error = ERR_get_error();
	    fatalf("Failed to set SSL cipher suite '%s': %s\n",
		cipher, ERR_error_string(ssl_error, NULL));
	}
    }
    debug(83, 1) ("Using certificate in %s\n", certfile);
    if (!SSL_CTX_use_certificate_chain_file(sslContext, certfile)) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Failed to acquire SSL certificate '%s': %s\n",
	    certfile, ERR_error_string(ssl_error, NULL));
	goto error;
    }
    debug(83, 1) ("Using private key in %s\n", keyfile);
    if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Failed to acquire SSL private key '%s': %s\n",
	    keyfile, ERR_error_string(ssl_error, NULL));
	goto error;
    }
    debug(83, 5) ("Comparing private and public SSL keys.\n");
    if (!SSL_CTX_check_private_key(sslContext)) {
	ssl_error = ERR_get_error();
	debug(83, 0) ("SSL private key '%s' does not match public key '%s': %s\n",
	    certfile, keyfile, ERR_error_string(ssl_error, NULL));
	goto error;
    }
    debug(83, 9) ("Setting RSA key generation callback.\n");
    SSL_CTX_set_tmp_rsa_callback(sslContext, ssl_temp_rsa_cb);

    debug(83, 9) ("Setting CA certificate locations.\n");
    if ((!SSL_CTX_load_verify_locations(sslContext, CAfile, CApath))) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Error error setting CA certificate locations: %s\n",
	    ERR_error_string(ssl_error, NULL));
	debug(83, 1) ("continuing anyway...\n");
    }
    if (!(fl & SSL_FLAG_NO_DEFAULT_CA) &&
	!SSL_CTX_set_default_verify_paths(sslContext)) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Error error setting default CA certificate location: %s\n",
	    ERR_error_string(ssl_error, NULL));
	debug(83, 1) ("continuing anyway...\n");
    }
    if (clientCA) {
	debug(83, 9) ("Set client certifying authority list.\n");
	SSL_CTX_set_client_CA_list(sslContext, SSL_load_client_CA_file(clientCA));
	if (fl & SSL_FLAG_DELAYED_AUTH) {
	    debug(83, 9) ("Not requesting client certificates until acl processing requires one\n");
	    SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, NULL);
	} else {
	    debug(83, 9) ("Requiring client certificates.\n");
	    SSL_CTX_set_verify(sslContext, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, ssl_verify_cb);
	}
    } else {
	debug(83, 9) ("Not requiring any client certificates\n");
	SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, NULL);
    }

    if (fl & SSL_FLAG_DONT_VERIFY_DOMAIN)
	SSL_CTX_set_ex_data(sslContext, ssl_ctx_ex_index_dont_verify_domain, (void *) -1);
    return sslContext;
  error:
    SSL_CTX_free(sslContext);
    return NULL;
}

SSL_CTX *
sslCreateClientContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options, const char *flags, const char *CAfile, const char *CApath)
{
    int ssl_error;
    SSL_METHOD *method;
    SSL_CTX *sslContext;
    long fl = ssl_parse_flags(flags);

    ssl_initialize();

    if (!keyfile)
	keyfile = certfile;
    if (!certfile)
	certfile = keyfile;

    debug(83, 1) ("Initialising SSL.\n");
    switch (version) {
    case 2:
	debug(83, 5) ("Using SSLv2.\n");
	method = SSLv2_client_method();
	break;
    case 3:
	debug(83, 5) ("Using SSLv3.\n");
	method = SSLv3_client_method();
	break;
    case 4:
	debug(83, 5) ("Using TLSv1.\n");
	method = TLSv1_client_method();
	break;
    case 1:
    default:
	debug(83, 5) ("Using SSLv2/SSLv3.\n");
	method = SSLv23_client_method();
	break;
    }

    sslContext = SSL_CTX_new(method);
    if (sslContext == NULL) {
	ssl_error = ERR_get_error();
	fatalf("Failed to allocate SSL context: %s\n",
	    ERR_error_string(ssl_error, NULL));
    }
    SSL_CTX_set_options(sslContext, ssl_parse_options(options));

    if (cipher) {
	debug(83, 5) ("Using chiper suite %s.\n", cipher);
	if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
	    ssl_error = ERR_get_error();
	    fatalf("Failed to set SSL cipher suite '%s': %s\n",
		cipher, ERR_error_string(ssl_error, NULL));
	}
    }
    if (certfile) {
	debug(83, 1) ("Using certificate in %s\n", certfile);
	if (!SSL_CTX_use_certificate_chain_file(sslContext, certfile)) {
	    ssl_error = ERR_get_error();
	    fatalf("Failed to acquire SSL certificate '%s': %s\n",
		certfile, ERR_error_string(ssl_error, NULL));
	}
	debug(83, 1) ("Using private key in %s\n", keyfile);
	if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
	    ssl_error = ERR_get_error();
	    fatalf("Failed to acquire SSL private key '%s': %s\n",
		keyfile, ERR_error_string(ssl_error, NULL));
	}
	debug(83, 5) ("Comparing private and public SSL keys.\n");
	if (!SSL_CTX_check_private_key(sslContext)) {
	    ssl_error = ERR_get_error();
	    fatalf("SSL private key '%s' does not match public key '%s': %s\n",
		certfile, keyfile, ERR_error_string(ssl_error, NULL));
	}
    }
    debug(83, 9) ("Setting RSA key generation callback.\n");
    SSL_CTX_set_tmp_rsa_callback(sslContext, ssl_temp_rsa_cb);

    if (fl & SSL_FLAG_DONT_VERIFY_PEER) {
	debug(83, 1) ("NOTICE: Peer certificates are not verified for validity!\n");
	SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, NULL);
    } else {
	debug(83, 9) ("Setting certificate verification callback.\n");
	SSL_CTX_set_verify(sslContext, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, ssl_verify_cb);
    }

    debug(83, 9) ("Setting CA certificate locations.\n");
    if ((!SSL_CTX_load_verify_locations(sslContext, CAfile, CApath))) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Error error setting CA certificate locations: %s\n",
	    ERR_error_string(ssl_error, NULL));
	debug(83, 1) ("continuing anyway...\n");
    }
    if (!(fl & SSL_FLAG_NO_DEFAULT_CA) &&
	!SSL_CTX_set_default_verify_paths(sslContext)) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Error error setting default CA certificate location: %s\n",
	    ERR_error_string(ssl_error, NULL));
	debug(83, 1) ("continuing anyway...\n");
    }
    return sslContext;
}

