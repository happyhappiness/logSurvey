    void deRegisterWithConn();
    void doClose();
    void initiateClose(const char *reason);

    AsyncCall::Pointer cbControlMsgSent; ///< notifies HttpControlMsg Source

    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
};
