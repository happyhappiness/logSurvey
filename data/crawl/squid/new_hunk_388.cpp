    virtual void closeServer();
    virtual bool doneWithServer() const;
    virtual const Comm::ConnectionPointer & dataConnection() const;
    virtual void abortAll(const char *reason);

    virtual Http::StatusCode failedHttpStatus(err_type &error);
    void ctrlClosed(const CommCloseCbParams &io);
