
        if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
            ssl_error = ERR_get_error();
            debugs(83, DBG_CRITICAL, "ERROR: Failed to set SSL cipher suite '" << cipher << "': " << ERR_error_string(ssl_error, NULL));
            SSL_CTX_free(sslContext);
            return NULL;
        }
    }

