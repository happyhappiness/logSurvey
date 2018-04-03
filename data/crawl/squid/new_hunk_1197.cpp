    const SBuf &connectionTag() const { return connectionTag_; }
    void connectionTag(const char *aTag) { connectionTag_ = aTag; }

    /// handle a control message received by context from a peer and call back
    virtual void writeControlMsgAndCall(ClientSocketContext *context, HttpReply *rep, AsyncCall::Pointer &call) = 0;

    /// ClientStream calls this to supply response header (once) and data
    /// for the current ClientSocketContext.
    virtual void handleReply(HttpReply *header, StoreIOBuffer receivedData) = 0;

    /// remove no longer needed leading bytes from the input buffer
    void consumeInput(const size_t byteCount);

    /* TODO: Make the methods below (at least) non-public when possible. */

    /// stop parsing the request and create context for relaying error info
    ClientSocketContext *abortRequestParsing(const char *const errUri);

protected:
    void startDechunkingRequest();
    void finishDechunkingRequest(bool withSuccess);
