    char *proxy_host;
    size_t list_width;
    String cwd_message;
    char *old_filepath;
    char typecode;
    MemBuf listing;		///< FTP directory listing in HTML format.

    GatewayFlags flags;

public:
    // these should all be private
    virtual void start();
    virtual Http::StatusCode failedHttpStatus(err_type &error);
    void loginParser(const char *, int escaped);
    int restartable();
    void appendSuccessHeader();
    void hackShortcut(StateMethod *nextState);
    void unhack();
    void readStor();
    void parseListing();
    MemBuf *htmlifyListEntry(const char *line);
    void completedListing(void);

    /// create a data channel acceptor and start listening.
    void listenForDataChannel(const Comm::ConnectionPointer &conn);

    int checkAuth(const HttpHeader * req_hdr);
    void checkUrlpath();
    void buildTitleUrl();
    void writeReplyBody(const char *, size_t len);
    void printfReplyBody(const char *fmt, ...);
    virtual void completeForwarding();
    void processHeadResponse();
    void processReplyBody();
    void setCurrentOffset(int64_t offset) { currentOffset = offset; }
    int64_t getCurrentOffset() const { return currentOffset; }

    virtual void dataChannelConnected(const CommConnectCbParams &io);
    static PF ftpDataWrite;
    virtual void timeout(const CommTimeoutCbParams &io);
    void ftpAcceptDataConnection(const CommAcceptCbParams &io);

    static HttpReply *ftpAuthRequired(HttpRequest * request, const char *realm);
    const char *ftpRealm(void);
    void loginFailed(void);

    virtual void haveParsedReplyHeaders();

    virtual bool haveControlChannel(const char *caller_name) const;

protected:
    virtual void handleControlReply();
    virtual void dataClosed(const CommCloseCbParams &io);

private:
    virtual bool mayReadVirginReplyBody() const;
    // BodyConsumer for HTTP: consume request body.
    virtual void handleRequestBodyProducerAborted();

    CBDATA_CLASS2(Gateway);
};

} // namespace Ftp

typedef Ftp::StateMethod FTPSM; // to avoid lots of non-changes

CBDATA_NAMESPACED_CLASS_INIT(Ftp, Gateway);

typedef struct {
    char type;
    int64_t size;
