#endif

Security::ContextPtr
sslCreateClientContext(const char *certfile, const char *keyfile, const char *cipher, long options, long fl)
{
    Ssl::Initialize();

#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
    Security::ContextPtr sslContext(SSL_CTX_new(TLS_client_method()));
#else
    Security::ContextPtr sslContext(SSL_CTX_new(SSLv23_client_method()));
#endif

    if (sslContext == NULL) {
        const int ssl_error = ERR_get_error();
        fatalf("Failed to allocate SSL context: %s\n",
               ERR_error_string(ssl_error, NULL));
    }

    SSL_CTX_set_options(sslContext, options);

