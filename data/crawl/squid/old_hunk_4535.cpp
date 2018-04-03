    virtual void closeServer();
    virtual void completeForwarding();
    virtual void abortTransaction(const char *reason);
    void processReplyBody();
    void writeCommand(const char *buf);

