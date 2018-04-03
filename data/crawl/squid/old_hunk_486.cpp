    SSLeay_add_ssl_algorithms();

#if HAVE_OPENSSL_ENGINE_H
    if (Config.SSL.ssl_engine) {
        ENGINE *e;
        if (!(e = ENGINE_by_id(Config.SSL.ssl_engine)))
            fatalf("Unable to find SSL engine '%s'\n", Config.SSL.ssl_engine);

        if (!ENGINE_set_default(e, ENGINE_METHOD_ALL)) {
            const int ssl_error = ERR_get_error();
            fatalf("Failed to initialise SSL engine: %s\n", ERR_error_string(ssl_error, NULL));
        }
    }
#else
    if (Config.SSL.ssl_engine)
        fatalf("Your OpenSSL has no SSL engine support\n");
#endif

    const char *defName = Config.SSL.certSignHash ? Config.SSL.certSignHash : SQUID_SSL_SIGN_HASH_IF_NONE;
    Ssl::DefaultSignHash = EVP_get_digestbyname(defName);
    if (!Ssl::DefaultSignHash)
        fatalf("Sign hash '%s' is not supported\n", defName);
