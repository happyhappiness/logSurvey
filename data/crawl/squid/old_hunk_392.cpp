    virtual void handleRequestBodyProducerAborted();
    virtual bool mayReadVirginReplyBody() const;
    virtual void completeForwarding();

    /* AsyncJob API */
    virtual void start();
