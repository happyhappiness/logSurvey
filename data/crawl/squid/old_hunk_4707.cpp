    void failReply (HttpReply *reply, http_status const &status);
    void keepaliveAccounting(HttpReply *);
    void checkDateSkew(HttpReply *);
    void haveParsedReplyHeaders();
    void transactionComplete();
    void writeReplyBody(const char *data, int len);
    void sendRequestEntityDone();
    void requestBodyHandler(MemBuf &);
    void sendRequestEntity(int fd, size_t size, comm_err_t errflag);
    mb_size_t buildRequestPrefix(HttpRequest * request,
                                 HttpRequest * orig_request,
                                 StoreEntry * entry,
