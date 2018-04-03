     }
 
     if (callback_ != NULL) {
-        typedef CommConnectCbParams Params;
-        Params &params = GetCommParams<Params>(callback_);
-        params.conn = conn_;
-        params.flag = errFlag;
-        params.xerrno = xerrno;
-        ScheduleCallHere(callback_);
+        // avoid scheduling cancelled callbacks, assuming they are common
+        // enough to make this extra check an optimization
+        if (callback_->canceled()) {
+            debugs(5, 4, conn_ << " not calling canceled " << *callback_ <<
+                   " [" << callback_->id << ']' );
+        } else {
+            typedef CommConnectCbParams Params;
+            Params &params = GetCommParams<Params>(callback_);
+            params.conn = conn_;
+            params.flag = errFlag;
+            params.xerrno = xerrno;
+            ScheduleCallHere(callback_);
+        }
         callback_ = NULL;
     }
 
-    if (temporaryFd_ >= 0) {
-        debugs(5, 4, HERE << conn_ << " closing temp FD " << temporaryFd_);
-        // it never reached fully open, so cleanup the FD handlers
-        // Note that comm_close() sequence does not happen for partially open FD
-        Comm::SetSelect(temporaryFd_, COMM_SELECT_WRITE, NULL, NULL, 0);
+    // The job will stop without this call because nil callback_ makes
+    // doneAll() true, but this explicit call creates nicer debugging.
+    mustStop(why);
+}
+
+/// cleans up this job I/O state without closing temporaryFd
+/// required before closing temporaryFd or keeping it in conn_
+/// leaves FD bare so must only be called via closeFd() or keepFd()
+void
+Comm::ConnOpener::cleanFd()
+{
+    debugs(5, 4, HERE << conn_ << " closing temp FD " << temporaryFd_);
+
+    Must(temporaryFd_ >= 0);
+    fde &f = fd_table[temporaryFd_];
+
+    // Our write_handler was set without using Comm::Write API, so we cannot
+    // use a cancellable Pointer-free job callback and simply cancel it here.
+    if (f.write_handler) {
+
+        /* XXX: We are about to remove write_handler, which was responsible
+         * for deleting write_data, so we have to delete write_data
+         * ourselves. Comm currently calls SetSelect handlers synchronously
+         * so if write_handler is set, we know it has not been called yet.
+         * ConnOpener converts that sync call into an async one, but only
+         * after deleting ptr, so that is not a problem.
+         */
+
+        delete static_cast<Pointer*>(f.write_data);
+        f.write_data = NULL;
+        f.write_handler = NULL;
+    }
+    // Comm::DoSelect does not do this when calling and resetting write_handler
+    // (because it expects more writes to come?). We could mimic that 
+    // optimization by resetting Comm "Select" state only when the FD is
+    // actually closed.
+    Comm::SetSelect(temporaryFd_, COMM_SELECT_WRITE, NULL, NULL, 0);
+ 
+    if (calls_.timeout_ != NULL) {
+        calls_.timeout_->cancel("Comm::ConnOpener::cleanFd");
+        calls_.timeout_ = NULL;
+    }
+    // Comm checkTimeouts() and commCloseAllSockets() do not clear .timeout 
+    // when calling timeoutHandler (XXX fix them), so we clear unconditionally.
+    f.timeoutHandler = NULL;
+    f.timeout = 0;
+
+    if (calls_.earlyAbort_ != NULL) {
+        comm_remove_close_handler(temporaryFd_, calls_.earlyAbort_);
         calls_.earlyAbort_ = NULL;
-        if (calls_.timeout_ != NULL) {
-            calls_.timeout_->cancel("Comm::ConnOpener::doneConnecting");
-            calls_.timeout_ = NULL;
-        }
-        fd_table[temporaryFd_].timeoutHandler = NULL;
-        fd_table[temporaryFd_].timeout = 0;
-        close(temporaryFd_);
-        fd_close(temporaryFd_);
-        temporaryFd_ = -1;
     }
+}
+
+/// cleans I/O state and ends I/O for temporaryFd_
+void
+Comm::ConnOpener::closeFd()
+{
+    if (temporaryFd_ < 0)
+        return;
+
+    cleanFd();
 
-    /* ensure cleared local state, we are done. */
-    conn_ = NULL;
+    // comm_close() below uses COMMIO_FD_WRITECB(fd)->active() to clear Comm
+    // "Select" state. It will not clear ours. XXX: It should always clear
+    // because a callback may have been active but was called before comm_close
+    // Update: we now do this in cleanFd()
+    // Comm::SetSelect(temporaryFd_, COMM_SELECT_WRITE, NULL, NULL, 0);
+
+    comm_close(temporaryFd_);
+    temporaryFd_ = -1;
+}
+
+/// cleans I/O state and moves temporaryFd_ to the conn_ for long-term use
+void
+Comm::ConnOpener::keepFd()
+{
+    Must(conn_ != NULL);
+    Must(temporaryFd_ >= 0);
+
+    cleanFd();
+
+    conn_->fd = temporaryFd_;
+    temporaryFd_ = -1;
 }
 
 void
 Comm::ConnOpener::start()
 {
     Must(conn_ != NULL);
 
-    /* get a socket open ready for connecting with */
+    /* outbound sockets have no need to be protocol agnostic. */
+    if (!(Ip::EnableIpv6&IPV6_SPECIAL_V4MAPPING) && conn_->remote.IsIPv4()) {
+        conn_->local.SetIPv4();
+    }
+
+    if (createFd())
+        connect();
+}
+
+/// called at the end of Comm::ConnOpener::DelayedConnectRetry event
+void
+Comm::ConnOpener::restart() {
+    debugs(5, 5, conn_ << " restarting after sleep");
+    calls_.sleep_ = false;
+
+    if (createFd())
+        connect();
+}
+
+/// Create a socket for the future connection or return false. 
+/// If false is returned, done() is guaranteed to return true and end the job.
+bool
+Comm::ConnOpener::createFd()
+{
+    Must(temporaryFd_ < 0);
+
+    // our initators signal abort by cancelling their callbacks
+    if (callback_ == NULL || callback_->canceled())
+        return false;
+
+    temporaryFd_ = comm_openex(SOCK_STREAM, IPPROTO_TCP, conn_->local, conn_->flags, conn_->tos, conn_->nfmark, host_);
     if (temporaryFd_ < 0) {
-        /* outbound sockets have no need to be protocol agnostic. */
-        if (!(Ip::EnableIpv6&IPV6_SPECIAL_V4MAPPING) && conn_->remote.IsIPv4()) {
-            conn_->local.SetIPv4();
-        }
-        temporaryFd_ = comm_openex(SOCK_STREAM, IPPROTO_TCP, conn_->local, conn_->flags, conn_->tos, conn_->nfmark, host_);
-        if (temporaryFd_ < 0) {
-            doneConnecting(COMM_ERR_CONNECT, 0);
-            return;
-        }
+        sendAnswer(COMM_ERR_CONNECT, 0, "Comm::ConnOpener::createFd");
+        return false;
     }
 
     typedef CommCbMemFunT<Comm::ConnOpener, CommCloseCbParams> abortDialer;
