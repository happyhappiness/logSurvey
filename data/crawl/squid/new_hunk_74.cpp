            fatalf("Unknown TLS option '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(tok.remaining()));
        }

    }

#if SSL_OP_NO_SSLv2
    // compliance with RFC 6176: Prohibiting Secure Sockets Layer (SSL) Version 2.0
    op = op | SSL_OP_NO_SSLv2;
#endif
    parsedOptions = op;

#elif USE_GNUTLS
    if (sslOptions.isEmpty()) {
        parsedOptions.reset();
        return;
    }

    const char *err = nullptr;
    const char *priorities = sslOptions.c_str();
    gnutls_priority_t op;
    if (gnutls_priority_init(&op, priorities, &err) != GNUTLS_E_SUCCESS) {
        fatalf("Unknown TLS option '%s'", err);
    }
    parsedOptions = Security::ParsedOptions(op, [](gnutls_priority_t p) {
            gnutls_priority_deinit(p);
    });
#endif
}

/**
