
    if (sslContext == NULL) {
        ssl_error = ERR_get_error();
        debugs(83, DBG_CRITICAL, "ERROR: Failed to allocate SSL context: " << ERR_error_string(ssl_error, NULL));
        return NULL;
    }

    SSL_CTX_set_options(sslContext, ssl_parse_options(options));
