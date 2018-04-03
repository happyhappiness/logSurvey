    bool concurrentRequestQueueFilled() const;

    /* PROXY protocol functionality */
    bool proxyProtocolValidateClient();
    bool parseProxyProtocolMagic();
    bool proxyProtocolError(bool isFatal);
