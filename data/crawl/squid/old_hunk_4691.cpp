
    bool done() const;
    virtual bool doneAll() const;
    virtual void doStop();
    void mustStop(const char *reason);

    // returns a temporary string depicting transaction status, for debugging
    const char *status() const;
    virtual void fillPendingStatus(MemBuf &buf) const;
