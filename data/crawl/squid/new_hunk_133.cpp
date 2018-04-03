        if (!SSL_CTX_set_cipher_list(ctx.get(), cipher)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to set SSL cipher suite '%s': %s\n",
                   cipher, Security::ErrorString(ssl_error));
        }
    }

