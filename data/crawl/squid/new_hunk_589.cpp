        debugs(3, DBG_IMPORTANT, "Initializing https:// proxy context");
        Config.ssl_client.sslContext = Security::ProxyOutgoingConfig.createClientContext(false);
        if (!Config.ssl_client.sslContext) {
#if USE_OPENSSL
            fatal("ERROR: Could not initialize https:// proxy context");
#else
            debugs(3, DBG_IMPORTANT, "ERROR: proxying https:// currently still requires --with-openssl");
#endif
        }
    }
