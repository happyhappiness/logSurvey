    void buildTitleUrl();
    void writeReplyBody(const char *, int len);
    void printfReplyBody(const char *fmt, ...);
    virtual int dataDescriptor() const;
    virtual void maybeReadVirginBody();
    virtual void closeServer();
    virtual void completeForwarding();
    virtual void abortTransaction(const char *reason);
    void processReplyBody();
    void writeCommand(const char *buf);

    static PF ftpSocketClosed;
    static CNCB ftpPasvCallback;
    static IOCB dataReadWrapper;
    static PF ftpDataWrite;
    static PF ftpTimeout;
    static IOCB ftpReadControlReply;
    static IOCB ftpWriteCommandCallback;
    static HttpReply *ftpAuthRequired(HttpRequest * request, const char *realm);
    static wordlist *ftpParseControlReply(char *, size_t, int *, int *);

    // sending of the request body to the server
    virtual void sentRequestBody(int fd, size_t size, comm_err_t errflag);
    virtual void doneSendingRequestBody();

    virtual bool doneWithServer() const;

private:
    // BodyConsumer for HTTP: consume request body.
    virtual void handleRequestBodyProducerAborted();

#if ICAP_CLIENT
public:
    void icapAclCheckDone(ICAPServiceRep::Pointer);

    bool icapAccessCheckPending;
#endif

};
