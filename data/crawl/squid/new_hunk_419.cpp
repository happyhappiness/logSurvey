    DeferredParams deferredparams;
    int64_t writtenToSocket;

private:
    void prepareReply(HttpReply *);
    void packChunk(const StoreIOBuffer &bodyData, MemBuf &);
    void packRange(StoreIOBuffer const &, MemBuf *);
    void doClose();

    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
};
