    char *old_reply;

protected:
    virtual void start();

    void initReadBuf();
    virtual void closeServer();
    virtual bool doneWithServer() const;
    virtual Http::StatusCode failedHttpStatus(err_type &error);
    void ctrlClosed(const CommCloseCbParams &io);
    void scheduleReadControlReply(int buffered_ok);
