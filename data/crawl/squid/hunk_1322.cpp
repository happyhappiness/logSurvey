     AsyncCall::Pointer closer; ///< Comm close handler callback
 };
 
-/// Base class for FTP over HTTP and FTP Gateway server state.
-class ServerStateData: public ::ServerStateData
+/// Base class for FTP Gateway and FTP Native client classes.
+class Client: public ::ServerStateData
 {
 public:
-    ServerStateData(FwdState *fwdState);
-    virtual ~ServerStateData();
+    explicit Client(FwdState *fwdState);
+    virtual ~Client();
 
+    /// handle a fatal transaction error, closing the control connection
     virtual void failed(err_type error = ERR_NONE, int xerrno = 0);
+
+    /// read timeout handler
     virtual void timeout(const CommTimeoutCbParams &io);
-    virtual const Comm::ConnectionPointer & dataConnection() const;
-    virtual void abortTransaction(const char *reason);
+
+    /* ServerStateData API */
+    virtual void maybeReadVirginBody();
+
     void writeCommand(const char *buf);
 
     /// extracts remoteAddr from PASV response, validates it,
