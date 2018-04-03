     StreamContext(uint32_t id, const Comm::ConnectionPointer &, ClientHttpRequest *);
     ~StreamContext();
 
+    /// register this stream with the Server
+    void registerWithConn();
+
+    /// whether the reply has started being sent
     bool startOfOutput() const;
+
+    /// update stream state after a write, may initiate more I/O
     void writeComplete(size_t size);
 
+    /// get more data to send
+    void pullData();
+
+    /// \return true if the HTTP request is for multiple ranges
+    bool multipartRangeRequest() const;
+
+    int64_t getNextRangeOffset() const;
+    bool canPackMoreRanges() const;
+    size_t lengthToSend(Range<int64_t> const &available) const;
+
+    clientStream_status_t socketState();
+
+    /// send an HTTP reply message headers and maybe some initial payload
+    void sendStartOfMessage(HttpReply *, StoreIOBuffer bodyData);
+    /// send some HTTP reply message payload
+    void sendBody(StoreIOBuffer bodyData);
+    /// update stream state when N bytes are being sent.
+    /// NP: Http1Server bytes actually not sent yet, just packed into a MemBuf ready
+    void noteSentBodyBytes(size_t);
+
+    /// add Range headers (if any) to the given HTTP reply message
+    void buildRangeHeader(HttpReply *);
+
+    clientStreamNode * getTail() const;
+    clientStreamNode * getClientReplyContext() const;
+
+    ConnStateData *getConn() const;
+
+    /// update state to reflect I/O error
+    void noteIoError(const int xerrno);
+
+    /// cleanup when the transaction has finished. may destroy 'this'
+    void finished();
+
+    /// terminate due to a send/write error (may continue reading)
+    void initiateClose(const char *reason);
+
+    void deferRecipientForLater(clientStreamNode *, HttpReply *, StoreIOBuffer receivedData);
+
 public:
     // NP: stream ID is relative to the connection, not global.
     uint32_t id; ///< stream ID within the client connection.
