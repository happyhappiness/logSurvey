    bool concurrentRequestQueueFilled() const;

    /* PROXY protocol functionality */
    void proxyProtocolValidateClient();
    bool parseProxyProtocolMagic();
    bool proxyProtocolError(bool isFatal);
