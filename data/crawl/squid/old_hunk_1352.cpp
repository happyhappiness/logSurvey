
    /* PROXY protocol functionality */
    bool proxyProtocolValidateClient();
    bool parseProxyProtocolMagic();
    bool proxyProtocolError(bool isFatal);

    /// whether PROXY protocol header is still expected on this port
    bool needProxyProtocolHeader_;

#if USE_AUTH