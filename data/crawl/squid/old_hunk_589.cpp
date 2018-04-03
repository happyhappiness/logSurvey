        debugs(3, DBG_IMPORTANT, "Initializing https:// proxy context");
        Config.ssl_client.sslContext = Security::ProxyOutgoingConfig.createClientContext(false);
        if (!Config.ssl_client.sslContext) {
            debugs(3, DBG_CRITICAL, "ERROR: Could not initialize https:// proxy context");
            self_destruct();
        }
    }
