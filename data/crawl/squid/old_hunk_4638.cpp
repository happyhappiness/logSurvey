
    bool parseHttpMsg(HttpMsg *msg); // true=success; false=needMore; throw=err
    bool mayReadMore() const;
    virtual bool doneReading() const;
    virtual bool doneWriting() const;
    bool doneWithIo() const;

    bool done() const;
    virtual bool doneAll() const;
    void mustStop(const char *reason);

    // called just before the 'done' transaction is deleted
    virtual void swanSong(); 

    // returns a temporary string depicting transaction status, for debugging
    const char *status() const;
    virtual void fillPendingStatus(MemBuf &buf) const;
    virtual void fillDoneStatus(MemBuf &buf) const;

    // useful for debugging
    virtual bool fillVirginHttpHeader(MemBuf&) const;

protected:
    Pointer self; // see comments in the class description above
    const int id; // transaction ID for debugging, unique across ICAP xactions

    int connection;     // FD of the ICAP server connection
