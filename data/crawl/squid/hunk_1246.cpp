     char *proxy_host;
     size_t list_width;
     String cwd_message;
-    char *old_request;
-    char *old_reply;
     char *old_filepath;
     char typecode;
     MemBuf listing;		///< FTP directory listing in HTML format.
 
-    // \todo: optimize ctrl and data structs member order, to minimize size
-    /// FTP control channel info; the channel is opened once per transaction
-    struct CtrlChannel: public FtpChannel {
-        char *buf;
-        size_t size;
-        size_t offset;
-        wordlist *message;
-        char *last_command;
-        char *last_reply;
-        int replycode;
-    } ctrl;
-
-    /// FTP data channel info; the channel may be opened/closed a few times
-    struct DataChannel: public FtpChannel {
-        MemBuf *readBuf;
-        char *host;
-        unsigned short port;
-        bool read_pending;
-    } data;
-
-    struct _ftp_flags flags;
+    GatewayFlags flags;
 
 public:
     // these should all be private
     virtual void start();
+    virtual Http::StatusCode failedHttpStatus(err_type &error);
     void loginParser(const char *, int escaped);
     int restartable();
     void appendSuccessHeader();
-    void hackShortcut(FTPSM * nextState);
-    void failed(err_type, int xerrno);
-    void failedErrorMessage(err_type, int xerrno);
+    void hackShortcut(StateMethod *nextState);
     void unhack();
-    void scheduleReadControlReply(int);
-    void handleControlReply();
     void readStor();
     void parseListing();
     MemBuf *htmlifyListEntry(const char *line);
     void completedListing(void);
-    void dataComplete();
-    void dataRead(const CommIoCbParams &io);
 
-    /// ignore timeout on CTRL channel. set read timeout on DATA channel.
-    void switchTimeoutToDataChannel();
     /// create a data channel acceptor and start listening.
-    void listenForDataChannel(const Comm::ConnectionPointer &conn, const char *note);
+    void listenForDataChannel(const Comm::ConnectionPointer &conn);
 
     int checkAuth(const HttpHeader * req_hdr);
     void checkUrlpath();
     void buildTitleUrl();
     void writeReplyBody(const char *, size_t len);
     void printfReplyBody(const char *fmt, ...);
-    virtual const Comm::ConnectionPointer & dataConnection() const;
-    virtual void maybeReadVirginBody();
-    virtual void closeServer();
     virtual void completeForwarding();
-    virtual void abortTransaction(const char *reason);
     void processHeadResponse();
     void processReplyBody();
-    void writeCommand(const char *buf);
     void setCurrentOffset(int64_t offset) { currentOffset = offset; }
     int64_t getCurrentOffset() const { return currentOffset; }
 
-    static CNCB ftpPasvCallback;
+    virtual void dataChannelConnected(const CommConnectCbParams &io);
     static PF ftpDataWrite;
-    void ftpTimeout(const CommTimeoutCbParams &io);
-    void ctrlClosed(const CommCloseCbParams &io);
-    void dataClosed(const CommCloseCbParams &io);
-    void ftpReadControlReply(const CommIoCbParams &io);
-    void ftpWriteCommandCallback(const CommIoCbParams &io);
+    virtual void timeout(const CommTimeoutCbParams &io);
     void ftpAcceptDataConnection(const CommAcceptCbParams &io);
 
     static HttpReply *ftpAuthRequired(HttpRequest * request, const char *realm);
     const char *ftpRealm(void);
     void loginFailed(void);
-    static wordlist *ftpParseControlReply(char *, size_t, int *, size_t *);
-
-    // sending of the request body to the server
-    virtual void sentRequestBody(const CommIoCbParams&);
-    virtual void doneSendingRequestBody();
 
     virtual void haveParsedReplyHeaders();
 
-    virtual bool doneWithServer() const;
     virtual bool haveControlChannel(const char *caller_name) const;
-    AsyncCall::Pointer dataCloser(); /// creates a Comm close callback
-    AsyncCall::Pointer dataOpener(); /// creates a Comm connect callback
+
+protected:
+    virtual void handleControlReply();
+    virtual void dataClosed(const CommCloseCbParams &io);
 
 private:
+    virtual bool mayReadVirginReplyBody() const;
     // BodyConsumer for HTTP: consume request body.
     virtual void handleRequestBodyProducerAborted();
 
-    CBDATA_CLASS2(FtpStateData);
+    CBDATA_CLASS2(Gateway);
 };
 
-CBDATA_CLASS_INIT(FtpStateData);
+} // namespace Ftp
+
+typedef Ftp::StateMethod FTPSM; // to avoid lots of non-changes
+
+CBDATA_NAMESPACED_CLASS_INIT(Ftp, Gateway);
 
-/// \ingroup ServerProtocolFTPInternal
 typedef struct {
     char type;
     int64_t size;
