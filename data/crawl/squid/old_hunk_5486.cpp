	debug(83, 5) ("Using chiper suite %s.\n", cipher);
	if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
	    ssl_error = ERR_get_error();
	    fatalf("Failed to set SSL cipher suite: %s\n",
		ERR_error_string(ssl_error, NULL));
	}
    }
    debug(83, 1) ("Using certificate in %s\n", certfile);
    if (!SSL_CTX_use_certificate_file(sslContext, certfile, SSL_FILETYPE_PEM)) {
	ssl_error = ERR_get_error();
	fatalf("Failed to acquire SSL certificate: %s\n",
	    ERR_error_string(ssl_error, NULL));
    }
    debug(83, 1) ("Using private key in %s\n", keyfile);
    if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
	ssl_error = ERR_get_error();
	fatalf("Failed to acquire SSL private key: %s\n",
	    ERR_error_string(ssl_error, NULL));
    }
    debug(83, 5) ("Comparing private and public SSL keys.\n");
    if (!SSL_CTX_check_private_key(sslContext))
	fatal("SSL private key does not match public key: %s\n");

    debug(83, 9) ("Setting RSA key generation callback.\n");
    SSL_CTX_set_tmp_rsa_callback(sslContext, ssl_temp_rsa_cb);

    debug(83, 9) ("Setting certificate verification callback.\n");
    SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, ssl_verify_cb);

    debug(83, 9) ("Setting default CA certificate location.\n");
    if (!SSL_CTX_set_default_verify_paths(sslContext)) {
	ssl_error = ERR_get_error();
	debug(83, 1) ("Error error setting default CA certificate location: %s\n",
	    ERR_error_string(ssl_error, NULL));
	debug(83, 1) ("continuing anyway...\n");
    }
    debug(83, 9) ("Set client certifying authority list.\n");
    SSL_CTX_set_client_CA_list(sslContext, SSL_load_client_CA_file(certfile));
    return sslContext;
}

