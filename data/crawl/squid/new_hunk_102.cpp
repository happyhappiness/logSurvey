    // compliance with RFC 6176: Prohibiting Secure Sockets Layer (SSL) Version 2.0
    op = op | SSL_OP_NO_SSLv2;
#endif
    theOut = new long(op);

#elif USE_GNUTLS
    const char *err = nullptr;
    const char *priorities = (sslOptions.isEmpty() ? nullptr : sslOptions.c_str());
    gnutls_priority_t op;
    int x = gnutls_priority_init(&op, priorities, &err);
    if (x != GNUTLS_E_SUCCESS) {
        fatalf("Unknown TLS option '%s'", err);
    }
    theOut.reset(op);

#endif
}

/**
