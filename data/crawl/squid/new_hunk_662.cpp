#endif

    if (sslContext == NULL) {
        const int ssl_error = ERR_get_error();
        fatalf("Failed to allocate SSL context: %s\n",
               ERR_error_string(ssl_error, NULL));
    }

    SSL_CTX_set_options(sslContext, options);

#if defined(SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)
    SSL_CTX_set_info_callback(sslContext, ssl_info_cb);
