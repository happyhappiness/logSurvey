    void clientPinnedConnectionRead(const CommIoCbParams &io);

    /// parse input buffer prefix into a single transfer protocol request
    virtual ClientSocketContext *parseOneRequest(Http::ProtocolVersion &ver) = 0;

    /// start processing a freshly parsed request
