    void buildTitleUrl();
    void writeReplyBody(const char *, int len);
    void printfReplyBody(const char *fmt, ...);
    void maybeReadData();
    void transactionComplete();
    void transactionForwardComplete();
    void transactionAbort();
    void processReplyBody();
    void writeCommand(const char *buf);

    static PF ftpSocketClosed;
    static CNCB ftpPasvCallback;
    static IOCB dataReadWrapper;
    static PF ftpDataWrite;
    static IOCB ftpDataWriteCallback;
    static PF ftpTimeout;
    static IOCB ftpReadControlReply;
    static IOCB ftpWriteCommandCallback;
    static HttpReply *ftpAuthRequired(HttpRequest * request, const char *realm);
    static CBCB ftpRequestBody;
    static wordlist *ftpParseControlReply(char *, size_t, int *, int *);

#if ICAP_CLIENT

public:
    void icapAclCheckDone(ICAPServiceRep::Pointer);
    virtual bool takeAdaptedHeaders(HttpReply *);
    virtual bool takeAdaptedBody(MemBuf *);
    virtual void finishAdapting();
    virtual void abortAdapting();
    virtual void icapSpaceAvailable();
    bool icapAccessCheckPending;
private:
    void backstabAdapter();
    void endAdapting();
#endif

};
