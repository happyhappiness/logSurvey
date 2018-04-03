    }
}

Security::ContextPtr
Security::PeerOptions::createBlankContext() const
{
    Security::ContextPtr t = nullptr;

#if USE_OPENSSL
#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
    t = SSL_CTX_new(TLS_client_method());
#else
    t = SSL_CTX_new(SSLv23_client_method());
#endif
    if (!t) {
        const auto x = ERR_error_string(ERR_get_error(), nullptr);
        fatalf("Failed to allocate TLS client context: %s\n", x);
    }

#elif USE_GNUTLS
    // Initialize for X.509 certificate exchange
    if (const int x = gnutls_certificate_allocate_credentials(&t)) {
        fatalf("Failed to allocate TLS client context: error=%d\n", x);
    }

#else
    fatal("Failed to allocate TLS client context: No TLS library\n");

#endif

    return t;
}

Security::ContextPtr
Security::PeerOptions::createClientContext(bool setOptions)
{
