    bool parseProxyProtocolHeader();
    bool parseProxy1p0();
    bool parseProxy2p0();
    bool proxyProtocolError(const char *reason);

    /// whether PROXY protocol header is still expected
    bool needProxyProtocolHeader_;