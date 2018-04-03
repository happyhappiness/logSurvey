
    /* PROXY protocol functionality */
    bool proxyProtocolValidateClient();
    bool findProxyProtocolMagic();
    bool parseProxy10();
    bool parseProxy20();
    bool proxyProtocolError(const char *reason = NULL);

    /// whether PROXY protocol header is still expected
    bool needProxyProtocolHeader_;

#if USE_AUTH