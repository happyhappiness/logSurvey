     useCertValidator_(true),
     certsDownloads(0)
 {
+    debugs(83, 5, "Security::PeerConnector constructed, this=" << (void*)this);
     // if this throws, the caller's cb dialer is not our CbDialer
     Must(dynamic_cast<CbDialer*>(callback->getDialer()));
 }
 
-Ssl::PeerConnector::~PeerConnector()
+Security::PeerConnector::~PeerConnector()
 {
-    debugs(83, 5, "Peer connector " << this << " gone");
+    debugs(83, 5, "Security::PeerConnector destructed, this=" << (void*)this);
 }
 
-bool Ssl::PeerConnector::doneAll() const
+bool Security::PeerConnector::doneAll() const
 {
     return (!callback || callback->canceled()) && AsyncJob::doneAll();
 }
 
 /// Preps connection and SSL state. Calls negotiate().
 void
-Ssl::PeerConnector::start()
+Security::PeerConnector::start()
 {
     AsyncJob::start();
 
-    if (prepareSocket() && initializeSsl())
+    Security::SessionPointer tmp;
+    if (prepareSocket() && initializeTls(tmp))
         negotiateSsl();
+    else
+        mustStop("Security::PeerConnector TLS socket initialize failed");
 }
 
 void
-Ssl::PeerConnector::commCloseHandler(const CommCloseCbParams &params)
+Security::PeerConnector::commCloseHandler(const CommCloseCbParams &params)
 {
-    debugs(83, 5, "FD " << params.fd << ", Ssl::PeerConnector=" << params.data);
-    connectionClosed("Ssl::PeerConnector::commCloseHandler");
+    debugs(83, 5, "FD " << params.fd << ", Security::PeerConnector=" << params.data);
+    connectionClosed("Security::PeerConnector::commCloseHandler");
 }
 
 void
-Ssl::PeerConnector::connectionClosed(const char *reason)
+Security::PeerConnector::connectionClosed(const char *reason)
 {
     mustStop(reason);
     callback = NULL;
 }
 
 bool
-Ssl::PeerConnector::prepareSocket()
+Security::PeerConnector::prepareSocket()
 {
     const int fd = serverConnection()->fd;
     if (!Comm::IsConnOpen(serverConn) || fd_table[serverConn->fd].closing()) {
-        connectionClosed("Ssl::PeerConnector::prepareSocket");
+        connectionClosed("Security::PeerConnector::prepareSocket");
         return false;
     }
 
     // watch for external connection closures
-    typedef CommCbMemFunT<Ssl::PeerConnector, CommCloseCbParams> Dialer;
-    closeHandler = JobCallback(9, 5, Dialer, this, Ssl::PeerConnector::commCloseHandler);
+    typedef CommCbMemFunT<Security::PeerConnector, CommCloseCbParams> Dialer;
+    closeHandler = JobCallback(9, 5, Dialer, this, Security::PeerConnector::commCloseHandler);
     comm_add_close_handler(fd, closeHandler);
     return true;
 }
 
-Security::SessionPtr
-Ssl::PeerConnector::initializeSsl()
+bool
+Security::PeerConnector::initializeTls(Security::SessionPointer &serverSession)
 {
+#if USE_OPENSSL
     Security::ContextPtr sslContext(getSslContext());
     assert(sslContext);
 
-    const int fd = serverConnection()->fd;
-
-    auto ssl = Ssl::CreateClient(sslContext, fd, "server https start");
-    if (!ssl) {
+    if (!Ssl::CreateClient(sslContext, serverConnection(), "server https start")) {
         ErrorState *anErr = new ErrorState(ERR_SOCKET_FAILURE, Http::scInternalServerError, request.getRaw());
         anErr->xerrno = errno;
         debugs(83, DBG_IMPORTANT, "Error allocating SSL handle: " << ERR_error_string(ERR_get_error(), NULL));
-
         noteNegotiationDone(anErr);
         bail(anErr);
-        return nullptr;
+        return false;
     }
 
+    // A TLS/SSL session has now been created for the connection and stored in fd_table
+    serverSession = fd_table[serverConnection()->fd].ssl;
+
     // If CertValidation Helper used do not lookup checklist for errors,
     // but keep a list of errors to send it to CertValidator
     if (!Ssl::TheConfig.ssl_crt_validator) {
