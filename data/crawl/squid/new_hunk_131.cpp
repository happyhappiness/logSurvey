    SSL_CTX *t = SSL_CTX_new(SSLv23_client_method());
#endif
    if (!t) {
        const auto x = ERR_get_error();
        fatalf("Failed to allocate TLS client context: %s\n", Security::ErrorString(x));
    }
    ctx.resetWithoutLocking(t);

#elif USE_GNUTLS
    // Initialize for X.509 certificate exchange
    gnutls_certificate_credentials_t t;
    if (const int x = gnutls_certificate_allocate_credentials(&t)) {
        fatalf("Failed to allocate TLS client context: %s\n", Security::ErrorString(x));
    }
    ctx.resetWithoutLocking(t);

