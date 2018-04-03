    /// stop parsing the request and create context for relaying error info
    ClientSocketContext *abortRequestParsing(const char *const errUri);

    /// client data which may need to forward as-is to server after an 
    /// on_unsupported_protocol tunnel decision.
    SBuf preservedClientData;
protected:
    void startDechunkingRequest();
    void finishDechunkingRequest(bool withSuccess);
