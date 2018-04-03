    virtual ~Xaction();

    void disableRetries();

    // comm handler wrappers, treat as private
    void noteCommConnected(const CommConnectCbParams &io);
