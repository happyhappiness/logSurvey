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

    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
