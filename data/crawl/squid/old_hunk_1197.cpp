    const SBuf &connectionTag() const { return connectionTag_; }
    void connectionTag(const char *aTag) { connectionTag_ = aTag; }

protected:
    void startDechunkingRequest();
    void finishDechunkingRequest(bool withSuccess);
