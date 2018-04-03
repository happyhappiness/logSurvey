    void startPinnedConnectionMonitoring();
    void clientPinnedConnectionRead(const CommIoCbParams &io);

private:
    int connFinishedWithConn(int size);
    void clientAfterReadingRequests();
    bool concurrentRequestQueueFilled() const;

#if USE_AUTH
    /// some user details that can be used to perform authentication on this connection
    Auth::UserRequest::Pointer auth_;
#endif

    HttpParser parser_;

    // XXX: CBDATA plays with public/private and leaves the following 'private' fields all public... :(

#if USE_OPENSSL
    bool switchedToHttps_;
    /// The SSL server host name appears in CONNECT request or the server ip address for the intercepted requests
