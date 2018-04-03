    /// stop parsing the request and create context for relaying error info
    ClientSocketContext *abortRequestParsing(const char *const errUri);

protected:
    void startDechunkingRequest();
    void finishDechunkingRequest(bool withSuccess);
