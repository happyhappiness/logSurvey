    bool multipartRangeRequest() const;
    void registerWithConn();
    void noteIoError(const int xerrno); ///< update state to reflect I/O error

private:
    void prepareReply(HttpReply * rep);
    void packChunk(const StoreIOBuffer &bodyData, MemBuf &mb);
    void packRange(StoreIOBuffer const &, MemBuf * mb);
    void doClose();
    void initiateClose(const char *reason);

    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
