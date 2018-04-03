     FtpWriteForwardedReply(context, reply, call);
 }
 
+static void
+FtpHandleEprtReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
+{
+    if (context->http->request->errType != ERR_NONE) {
+        FtpWriteCustomReply(context, 502, "Server does not support PASV (converted from EPRT)", reply);
+        return;
+    }
+
+    FtpWriteCustomReply(context, 200, "EPRT successfully converted to PASV.");
+
+    // and wait for RETR
+}
+
+static void
+FtpHandleEpsvReply(ClientSocketContext *context, const HttpReply *reply, StoreIOBuffer data)
+{
+    if (context->http->request->errType != ERR_NONE) {
+        FtpWriteCustomReply(context, 502, "Cannot connect to server", reply);
+        return;
+    }
+
+    FtpCloseDataConnection(context->getConn());
+
+    Comm::ConnectionPointer conn = new Comm::Connection;
+    ConnStateData * const connState = context->getConn();
+    conn->flags = COMM_NONBLOCKING;
+    conn->local = connState->transparent() ?
+                  connState->port->s : context->clientConnection->local;
+    conn->local.port(0);
+    const char *const note = connState->ftp.uri.termedBuf();
+    comm_open_listener(SOCK_STREAM, IPPROTO_TCP, conn, note);
+    if (!Comm::IsConnOpen(conn)) {
+            debugs(5, DBG_CRITICAL, "comm_open_listener failed: " <<
+                   conn->local << " error: " << errno);
+            FtpWriteCustomReply(context, 451, "Internal error");
+            return;
+    }
+
+    typedef CommCbFunPtrCallT<CommAcceptCbPtrFun> AcceptCall;
+    RefCount<AcceptCall> subCall = commCbCall(5, 5, "FtpAcceptDataConnection",
+        CommAcceptCbPtrFun(FtpAcceptDataConnection, connState));
+    Subscription::Pointer sub = new CallSubscription<AcceptCall>(subCall);
+    connState->ftp.listener = subCall.getRaw();
+    connState->ftp.dataListenConn = conn;
+    AsyncJob::Start(new Comm::TcpAcceptor(conn, note, sub));
+
+    // conn->fd is the client data connection (and its local port)
+    const unsigned int port = comm_local_port(conn->fd);
+    conn->local.port(port);
+
+    // In interception setups, we combine remote server address with a
+    // local port number and hope that traffic will be redirected to us.
+    MemBuf mb;
+    mb.init();
+    mb.Printf("229 Entering Extended Passive Mode (|||%u|)\r\n", port);
+
+    debugs(11, 3, Raw("writing", mb.buf, mb.size));
+    FtpWriteReply(context, mb);
+}
+
 /// writes FTP error response with given status and reply-derived error details
 static void
 FtpWriteErrorReply(ClientSocketContext *context, const HttpReply *reply, const int status)
