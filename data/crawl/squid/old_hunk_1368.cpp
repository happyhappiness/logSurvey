    void clientAfterReadingRequests();
    bool concurrentRequestQueueFilled() const;

#if USE_AUTH
    /// some user details that can be used to perform authentication on this connection
    Auth::UserRequest::Pointer auth_;