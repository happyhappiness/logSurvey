 
 static PSC fwdPeerSelectionCompleteWrapper;
 static CLCB fwdServerClosedWrapper;
-#if USE_OPENSSL
-static PF fwdNegotiateSSLWrapper;
-#endif
 static CNCB fwdConnectDoneWrapper;
 
 static OBJH fwdStats;
 
 #define MAX_FWD_STATS_IDX 9
 static int FwdReplyCodes[MAX_FWD_STATS_IDX + 1][Http::scInvalidHeader + 1];
 
-static PconnPool *fwdPconnPool = new PconnPool("server-side");
+static PconnPool *fwdPconnPool = new PconnPool("server-side", NULL);
 CBDATA_CLASS_INIT(FwdState);
 
+#if USE_OPENSSL
+class FwdStatePeerAnswerDialer: public CallDialer, public Ssl::PeerConnector::CbDialer
+{
+public:
+    typedef void (FwdState::*Method)(Ssl::PeerConnectorAnswer &);
+
+    FwdStatePeerAnswerDialer(Method method, FwdState *fwd):
+            method_(method), fwd_(fwd), answer_() {}
+
+    /* CallDialer API */
+    virtual bool canDial(AsyncCall &call) { return fwd_.valid(); }
+    void dial(AsyncCall &call) { ((&(*fwd_))->*method_)(answer_); }
+    virtual void print(std::ostream &os) const {
+        os << '(' << fwd_.get() << ", " << answer_ << ')';
+    }
+
+    /* Ssl::PeerConnector::CbDialer API */
+    virtual Ssl::PeerConnectorAnswer &answer() { return answer_; }
+
+private:
+    Method method_;
+    CbcPointer<FwdState> fwd_;
+    Ssl::PeerConnectorAnswer answer_;
+};
+#endif
+
 void
 FwdState::abort(void* d)
 {
     FwdState* fwd = (FwdState*)d;
     Pointer tmp = fwd; // Grab a temporary pointer to keep the object alive during our scope.
 
     if (Comm::IsConnOpen(fwd->serverConnection())) {
-        comm_remove_close_handler(fwd->serverConnection()->fd, fwdServerClosedWrapper, fwd);
-        debugs(17, 3, HERE << "store entry aborted; closing " <<
-               fwd->serverConnection());
-        fwd->serverConnection()->close();
+        fwd->closeServerConnection("store entry aborted");
     } else {
         debugs(17, 7, HERE << "store entry aborted; no connection to close");
     }
     fwd->serverDestinations.clear();
     fwd->self = NULL;
 }
 
+void
+FwdState::closeServerConnection(const char *reason)
+{
+    debugs(17, 3, "because " << reason << "; " << serverConn);
+    comm_remove_close_handler(serverConn->fd, fwdServerClosedWrapper, this);
+    fwdPconnPool->noteUses(fd_table[serverConn->fd].pconn.uses);
+    serverConn->close();
+}
+
 /**** PUBLIC INTERFACE ********************************************************/
 
 FwdState::FwdState(const Comm::ConnectionPointer &client, StoreEntry * e, HttpRequest * r, const AccessLogEntryPointer &alp):
