 {
     IdentStateData *state = (IdentStateData *)data;
     identCallback(state, NULL);
-    comm_close(state->fd);
+    state->conn->close();
     hash_remove_link(ident_hash, (hash_link *) state);
     xfree(state->hash.key);
     cbdataFree(state);
 }
 
 void
-Ident::Timeout(int fd, void *data)
+Ident::Timeout(const CommTimeoutCbParams &io)
 {
-    IdentStateData *state = (IdentStateData *)data;
-    debugs(30, 3, "identTimeout: FD " << fd << ", " << state->my_peer);
-
-    comm_close(fd);
+    debugs(30, 3, HERE << io.conn);
+    io.conn->close();
 }
 
 void
-Ident::ConnectDone(int fd, const DnsLookupDetails &, comm_err_t status, int xerrno, void *data)
+Ident::ConnectDone(const Comm::ConnectionPointer &conn, comm_err_t status, int xerrno, void *data)
 {
     IdentStateData *state = (IdentStateData *)data;
-    IdentClient *c;
 
     if (status != COMM_OK) {
-        /* Failed to connect */
-        comm_close(fd);
+        if (status == COMM_TIMEOUT) {
+            debugs(30, 3, "IDENT connection timeout to " << state->conn->remote);
+        }
         return;
     }
 
+    assert(conn != NULL && conn == state->conn);
+
     /*
      * see if any of our clients still care
      */
+    IdentClient *c;
     for (c = state->clients; c; c = c->next) {
         if (cbdataReferenceValid(c->callback_data))
             break;
     }
 
     if (c == NULL) {
         /* no clients care */
-        comm_close(fd);
+        conn->close();
         return;
     }
 
+    comm_add_close_handler(conn->fd, Ident::Close, state);
+
     MemBuf mb;
     mb.init();
     mb.Printf("%d, %d\r\n",
-              state->my_peer.GetPort(),
-              state->me.GetPort());
-
+              conn->remote.GetPort(),
+              conn->local.GetPort());
     AsyncCall::Pointer nil;
-    Comm::Write(fd, &mb, nil);
-    comm_read(fd, state->buf, BUFSIZ, Ident::ReadReply, state);
-    commSetTimeout(fd, Ident::TheConfig.timeout, Ident::Timeout, state);
+    Comm::Write(conn, &mb, nil);
+    AsyncCall::Pointer readCall = commCbCall(5,4, "Ident::ReadReply",
+                                             CommIoCbPtrFun(Ident::ReadReply, state));
+    comm_read(conn, state->buf, IDENT_BUFSIZE, readCall);
+    AsyncCall::Pointer timeoutCall = commCbCall(5,4, "Ident::Timeout",
+                                                CommTimeoutCbPtrFun(Ident::Timeout, state));
+    commSetConnTimeout(conn, Ident::TheConfig.timeout, timeoutCall);
 }
 
 void
-Ident::ReadReply(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
+Ident::ReadReply(const Comm::ConnectionPointer &conn, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
 {
     IdentStateData *state = (IdentStateData *)data;
     char *ident = NULL;
     char *t = NULL;
 
-    assert (buf == state->buf);
+    assert(buf == state->buf);
+    assert(conn->fd == state->conn->fd);
 
     if (flag != COMM_OK || len <= 0) {
-        comm_close(fd);
+        state->conn->close();
         return;
     }
 
