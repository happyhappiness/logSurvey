      */
 
     /* Accept a new connection */
-    ConnectionDetail newConnDetails;
-    int newFd = -1;
-    const comm_err_t flag = oldAccept(newConnDetails, &newFd);
+    ConnectionPointer newConnDetails = new Connection();
+    const comm_err_t flag = oldAccept(newConnDetails);
 
     /* Check for errors */
-    if (!isOpen(newFd)) {
+    if (!newConnDetails->isOpen()) {
 
         if (flag == COMM_NOMESSAGE) {
             /* register interest again */
-            debugs(5, 5, HERE << "try later: FD " << fd << " handler Subscription: " << theCallSub);
-            SetSelect(fd, COMM_SELECT_READ, doAccept, this, 0);
+            debugs(5, 5, HERE << "try later: " << conn << " handler Subscription: " << theCallSub);
+            SetSelect(conn->fd, COMM_SELECT_READ, doAccept, this, 0);
             return;
         }
 
         // A non-recoverable error; notify the caller */
         debugs(5, 5, HERE << "non-recoverable error:" << status() << " handler Subscription: " << theCallSub);
-        notify(flag, newConnDetails, newFd);
+        notify(flag, newConnDetails);
         mustStop("Listener socket closed");
         return;
     }
 
-    debugs(5, 5, HERE << "Listener: FD " << fd <<
-           " accepted new connection from " << newConnDetails.peer <<
+    debugs(5, 5, HERE << "Listener: " << conn <<
+           " accepted new connection " << newConnDetails <<
            " handler Subscription: " << theCallSub);
-    notify(flag, newConnDetails, newFd);
+    notify(flag, newConnDetails);
 }
 
 void
 Comm::TcpAcceptor::acceptNext()
 {
-    Must(isOpen(fd));
-    debugs(5, 2, HERE << "connection on FD " << fd);
+    Must(IsConnOpen(conn));
+    debugs(5, 2, HERE << "connection on " << conn);
     acceptOne();
 }
 
-// XXX: obsolete comment?
-// NP: can't be a const function because syncWithComm() side effects hit theCallSub->callback().
 void
-Comm::TcpAcceptor::notify(const comm_err_t flag, const ConnectionDetail &connDetails, int newFd) const
+Comm::TcpAcceptor::notify(const comm_err_t flag, const Comm::ConnectionPointer &newConnDetails) const
 {
     // listener socket handlers just abandon the port with COMM_ERR_CLOSING
     // it should only happen when this object is deleted...
