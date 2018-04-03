    void prepareReply(HttpReply * rep);
    void packRange(StoreIOBuffer const &, MemBuf * mb);
    void deRegisterWithConn();
    bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
    bool connRegistered_;
};
