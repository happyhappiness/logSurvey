
    void pinNewConnection(const Comm::ConnectionPointer &pinServer, HttpRequest *request, CachePeer *aPeer, bool auth);

    /* PROXY protocol functionality */
    bool proxyProtocolValidateClient();
    bool parseProxyProtocolHeader();
    bool parseProxy1p0();
    bool parseProxy2p0();
    bool proxyProtocolError(const char *reason);

    /// whether PROXY protocol header is still expected
    bool needProxyProtocolHeader_;

#if USE_AUTH
    /// some user details that can be used to perform authentication on this connection
    Auth::UserRequest::Pointer auth_;