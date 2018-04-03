         handleControlReply();
     } else {
         /* XXX What about Config.Timeout.read? */
-        comm_read(ctrl.fd, ctrl.buf + ctrl.offset, ctrl.size - ctrl.offset, ftpReadControlReply, this);
+	typedef CommCbMemFunT<FtpStateData, CommIoCbParams> Dialer;
+	AsyncCall::Pointer reader=asyncCall(9, 5, "FtpStateData::ftpReadControlReply",
+				    Dialer(this, &FtpStateData::ftpReadControlReply));
+	comm_read(ctrl.fd, ctrl.buf + ctrl.offset, ctrl.size - ctrl.offset, reader);
         /*
          * Cancel the timeout on the Data socket (if any) and
          * establish one on the control socket.
          */
 
-        if (data.fd > -1)
-            commSetTimeout(data.fd, -1, NULL, NULL);
+        if (data.fd > -1){
+	    AsyncCall::Pointer nullCall =  NULL;
+            commSetTimeout(data.fd, -1, nullCall);
+	}
+
+	typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
+	AsyncCall::Pointer timeoutCall =  asyncCall(9, 5, "FtpStateData::ftpTimeout",
+					    TimeoutDialer(this,&FtpStateData::ftpTimeout));
 
-        commSetTimeout(ctrl.fd, Config.Timeout.read, ftpTimeout,
-                       this);
+        commSetTimeout(ctrl.fd, Config.Timeout.read, timeoutCall);
     }
 }
 
-void
-FtpStateData::ftpReadControlReply(int fd, char *buf, size_t len, comm_err_t errflag, int xerrno, void *data)
+void FtpStateData::ftpReadControlReply(const CommIoCbParams &io)
 {
-    FtpStateData *ftpState = (FtpStateData *)data;
-    StoreEntry *entry = ftpState->entry;
-    debugs(9, 3, HERE "FD " << fd << ", Read " << len << " bytes");
+    debugs(9, 3, "ftpReadControlReply: FD " << io.fd << ", Read " << io.size << " bytes");
 
-    if (len > 0) {
-        kb_incr(&statCounter.server.all.kbytes_in, len);
-        kb_incr(&statCounter.server.ftp.kbytes_in, len);
+    if (io.size > 0) {
+        kb_incr(&statCounter.server.all.kbytes_in, io.size);
+        kb_incr(&statCounter.server.ftp.kbytes_in, io.size);
     }
 
-    if (errflag == COMM_ERR_CLOSING)
+    if (io.flag == COMM_ERR_CLOSING)
         return;
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        ftpState->abortTransaction("entry aborted during control reply read");
+        abortTransaction("entry aborted during control reply read");
         return;
     }
 
-    assert(ftpState->ctrl.offset < ftpState->ctrl.size);
+    assert(ctrl.offset < ctrl.size);
 
-    if (errflag == COMM_OK && len > 0) {
-        fd_bytes(fd, len, FD_READ);
+    if (io.flag == COMM_OK && io.size > 0) {
+        fd_bytes(io.fd, io.size, FD_READ);
     }
 
+    if (io.flag != COMM_OK || io.size < 0) {
+        debugs(50, ignoreErrno(io.xerrno) ? 3 : DBG_IMPORTANT, 
+            "ftpReadControlReply: read error: " << xstrerr(io.xerrno));
 
-    if (errflag != COMM_OK || len < 0) {
-         debugs(50, ignoreErrno(xerrno) ? 3 : DBG_IMPORTANT, "ftpReadControlReply: read error: " << xstrerr(xerrno));
-
-        if (ignoreErrno(xerrno)) {
-            ftpState->scheduleReadControlReply(0);
+        if (ignoreErrno(io.xerrno)) {
+            scheduleReadControlReply(0);
         } else {
-            ftpState->failed(ERR_READ_ERROR, xerrno);
+            failed(ERR_READ_ERROR, io.xerrno);
             /* failed closes ctrl.fd and frees ftpState */
             return;
         }
 
         return;
     }
 
-    if (len == 0) {
+    if (io.size == 0) {
         if (entry->store_status == STORE_PENDING) {
-            ftpState->failed(ERR_FTP_FAILURE, 0);
+            failed(ERR_FTP_FAILURE, 0);
             /* failed closes ctrl.fd and frees ftpState */
             return;
         }
 
     /* XXX this may end up having to be serverComplete() .. */
-        ftpState->abortTransaction("zero control reply read");
+        abortTransaction("zero control reply read");
         return;
     }
 
-    len += ftpState->ctrl.offset;
-    ftpState->ctrl.offset = len;
-    assert(len <= ftpState->ctrl.size);
-    ftpState->handleControlReply();
+    unsigned int len =io.size + ctrl.offset;
+    ctrl.offset = len;
+    assert(len <= ctrl.size);
+    handleControlReply();
 }
 
 void
