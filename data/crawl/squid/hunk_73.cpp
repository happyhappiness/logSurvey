 void
 Security::PeerConnector::connectionClosed(const char *reason)
 {
+    debugs(83, 5, reason << " socket closed/closing. this=" << (void*)this);
     mustStop(reason);
     callback = NULL;
 }
 
 bool
 Security::PeerConnector::prepareSocket()
 {
-    const int fd = serverConnection()->fd;
-    if (!Comm::IsConnOpen(serverConn) || fd_table[serverConn->fd].closing()) {
+    debugs(83, 5, serverConnection() << ", this=" << (void*)this);
+    if (!Comm::IsConnOpen(serverConnection()) || fd_table[serverConnection()->fd].closing()) {
         connectionClosed("Security::PeerConnector::prepareSocket");
         return false;
     }
 
+    debugs(83, 5, serverConnection());
+
     // watch for external connection closures
     typedef CommCbMemFunT<Security::PeerConnector, CommCloseCbParams> Dialer;
     closeHandler = JobCallback(9, 5, Dialer, this, Security::PeerConnector::commCloseHandler);
-    comm_add_close_handler(fd, closeHandler);
+    comm_add_close_handler(serverConnection()->fd, closeHandler);
     return true;
 }
 
 bool
 Security::PeerConnector::initialize(Security::SessionPointer &serverSession)
 {
-#if USE_OPENSSL
     Security::ContextPointer ctx(getTlsContext());
-    assert(ctx);
+    debugs(83, 5, serverConnection() << ", ctx=" << (void*)ctx.get());
 
-    if (!Ssl::CreateClient(ctx, serverConnection(), "server https start")) {
+    if (!ctx || !Security::CreateClientSession(ctx, serverConnection(), "server https start")) {
         const auto xerrno = errno;
-        const auto ssl_error = ERR_get_error();
+        if (!ctx) {
+            debugs(83, DBG_IMPORTANT, "Error initializing TLS connection: No security context.");
+        } // else CreateClientSession() did the appropriate debugs() already
         ErrorState *anErr = new ErrorState(ERR_SOCKET_FAILURE, Http::scInternalServerError, request.getRaw());
         anErr->xerrno = xerrno;
-        debugs(83, DBG_IMPORTANT, "Error allocating TLS handle: " << Security::ErrorString(ssl_error));
         noteNegotiationDone(anErr);
         bail(anErr);
         return false;
     }
 
     // A TLS/SSL session has now been created for the connection and stored in fd_table
     serverSession = fd_table[serverConnection()->fd].ssl;
+    debugs(83, 5, serverConnection() << ", session=" << (void*)serverSession.get());
 
+#if USE_OPENSSL
     // If CertValidation Helper used do not lookup checklist for errors,
     // but keep a list of errors to send it to CertValidator
     if (!Ssl::TheConfig.ssl_crt_validator) {
