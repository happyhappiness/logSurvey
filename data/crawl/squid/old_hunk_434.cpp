        }
    }

    // TODO: support loading multiple cert/key pairs
    auto &keys = peer.certs.front();
    if (!keys.certFile.isEmpty()) {
        debugs(83, DBG_IMPORTANT, "Using certificate in " << keys.certFile);

        const char *certfile = keys.certFile.c_str();
        if (!SSL_CTX_use_certificate_chain_file(sslContext, certfile)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to acquire SSL certificate '%s': %s\n",
                   certfile, ERR_error_string(ssl_error, NULL));
        }

        debugs(83, DBG_IMPORTANT, "Using private key in " << keys.privateKeyFile);
        const char *keyfile = keys.privateKeyFile.c_str();
        ssl_ask_password(sslContext, keyfile);

        if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to acquire SSL private key '%s': %s\n",
                   keyfile, ERR_error_string(ssl_error, NULL));
        }

        debugs(83, 5, "Comparing private and public SSL keys.");

        if (!SSL_CTX_check_private_key(sslContext)) {
            const int ssl_error = ERR_get_error();
            fatalf("SSL private key '%s' does not match public key '%s': %s\n",
                   certfile, keyfile, ERR_error_string(ssl_error, NULL));
        }
    }
