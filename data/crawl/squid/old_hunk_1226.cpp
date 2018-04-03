    /// remove no longer needed leading bytes from the input buffer
    void consumeInput(const size_t byteCount);

protected:
    void startDechunkingRequest();
    void finishDechunkingRequest(bool withSuccess);
