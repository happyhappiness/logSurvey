    DeferredParams deferredparams;
    int64_t writtenToSocket;

    void pullData();
    int64_t getNextRangeOffset() const;
    bool canPackMoreRanges() const;
    clientStream_status_t socketState();
    void sendBody(HttpReply * rep, StoreIOBuffer bodyData);
    void sendStartOfMessage(HttpReply * rep, StoreIOBuffer bodyData);
    size_t lengthToSend(Range<int64_t> const &available);
    void noteSentBodyBytes(size_t);
    void buildRangeHeader(HttpReply * rep);
    clientStreamNode * getTail() const;
    clientStreamNode * getClientReplyContext() const;
    ConnStateData *getConn() const;
    void finished(); ///< cleanup when the transaction has finished. may destroy 'this'
    void deferRecipientForLater(clientStreamNode * node, HttpReply * rep, StoreIOBuffer receivedData);
    bool multipartRangeRequest() const;
    void registerWithConn();
    void noteIoError(const int xerrno); ///< update state to reflect I/O error
    void initiateClose(const char *reason); ///< terminate due to a send/write error (may continue reading)

private:
    void prepareReply(HttpReply * rep);
    void packChunk(const StoreIOBuffer &bodyData, MemBuf &mb);
    void packRange(StoreIOBuffer const &, MemBuf * mb);
    void doClose();

private:
    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
};
