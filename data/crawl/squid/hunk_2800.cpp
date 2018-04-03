      */
 
     /* Accept a new connection */
-    ConnectionDetail connDetails;
-    int newfd = oldAccept(connDetails);
+    ConnectionDetail newConnDetails;
+    int newFd = -1;
+    const comm_err_t flag = oldAccept(newConnDetails, &newFd);
 
     /* Check for errors */
-    if (newfd < 0) {
+    if (!isOpen(newFd)) {
 
-        if (newfd == COMM_NOMESSAGE) {
+        if (flag == COMM_NOMESSAGE) {
             /* register interest again */
-            debugs(5, 5, HERE << "try later: FD " << fd << " handler: " << theCallback);
+            debugs(5, 5, HERE << "try later: FD " << fd << " handler Subscription: " << theCallSub);
             SetSelect(fd, COMM_SELECT_READ, doAccept, this, 0);
             return;
         }
 
         // A non-recoverable error; notify the caller */
-        debugs(5, 5, HERE << "non-recoverable error: FD " << fd << " handler: " << theCallback);
-        notify(-1, COMM_ERROR, connDetails);
-        mayAcceptMore = false;
+        debugs(5, 5, HERE << "non-recoverable error:" << status() << " handler Subscription: " << theCallSub);
+        notify(flag, newConnDetails, newFd);
+        mustStop("Listener socket closed");
         return;
     }
 
-    debugs(5, 5, HERE << "accepted: FD " << fd <<
-           " newfd: " << newfd << " from: " << connDetails.peer <<
-           " handler: " << theCallback);
-    notify(newfd, COMM_OK, connDetails);
+    debugs(5, 5, HERE << "Listener: FD " << fd <<
+           " accepted new connection from " << newConnDetails.peer <<
+           " handler Subscription: " << theCallSub);
+    notify(flag, newConnDetails, newFd);
 }
 
 void
-Comm::ListenStateData::acceptNext()
+Comm::TcpAcceptor::acceptNext()
 {
-    assert(isOpen(fd));
+    Must(isOpen(fd));
     debugs(5, 2, HERE << "connection on FD " << fd);
     acceptOne();
 }
 
+// XXX: obsolete comment?
+// NP: can't be a const function because syncWithComm() side effects hit theCallSub->callback().
 void
-Comm::ListenStateData::notify(int newfd, comm_err_t flag, const ConnectionDetail &connDetails)
+Comm::TcpAcceptor::notify(const comm_err_t flag, const ConnectionDetail &connDetails, int newFd) const
 {
     // listener socket handlers just abandon the port with COMM_ERR_CLOSING
     // it should only happen when this object is deleted...
     if (flag == COMM_ERR_CLOSING) {
         return;
     }
 
-    if (theCallback != NULL) {
-        typedef CommAcceptCbParams Params;
-        Params &params = GetCommParams<Params>(theCallback);
+    if (theCallSub != NULL) {
+        AsyncCall::Pointer call = theCallSub->callback();
+        CommAcceptCbParams &params = GetCommParams<CommAcceptCbParams>(call);
         params.fd = fd;
-        params.nfd = newfd;
+        params.nfd = newFd;
         params.details = connDetails;
         params.flag = flag;
         params.xerrno = errcode;
-        ScheduleCallHere(theCallback);
-        if (!mayAcceptMore)
-            theCallback = NULL;
+        ScheduleCallHere(call);
     }
 }
 
 /**
  * accept() and process
- * Wait for an incoming connection on FD.
+ * Wait for an incoming connection on our listener socket.
+ *
+ * \retval COMM_OK         success. details parameter filled.
+ * \retval COMM_NOMESSAGE  attempted accept() but nothing useful came in.
+ * \retval COMM_ERROR      an outright failure occured.
+ *                         Or if this client has too many connections already.
  */
-int
-Comm::ListenStateData::oldAccept(ConnectionDetail &details)
+comm_err_t
+Comm::TcpAcceptor::oldAccept(ConnectionDetail &details, int *newFd)
 {
     PROF_start(comm_accept);
     statCounter.syscalls.sock.accepts++;
