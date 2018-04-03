 
 std::ostream &Ipc::StartListeningCb::startPrint(std::ostream &os) const
 {
-    return os << "(FD " << fd << ", err=" << errNo;
+    return os << "(" << conn << ", err=" << errNo;
 }
 
-
-void Ipc::StartListening(int sock_type, int proto, Ip::Address &addr,
-                         int flags, FdNoteId fdNote, AsyncCall::Pointer &callback)
+void
+Ipc::StartListening(int sock_type, int proto, const Comm::ConnectionPointer &listenConn,
+                    FdNoteId fdNote, AsyncCall::Pointer &callback, const Subscription::Pointer &sub)
 {
-    OpenListenerParams p;
-    p.sock_type = sock_type;
-    p.proto = proto;
-    p.addr = addr;
-    p.flags = flags;
-    p.fdNote = fdNote;
-
     if (UsingSmp()) { // if SMP is on, share
+        OpenListenerParams p;
+        p.sock_type = sock_type;
+        p.proto = proto;
+        p.addr = listenConn->local;
+        p.flags = listenConn->flags;
+        p.fdNote = fdNote;
+        p.handlerSubscription = sub;
+
         Ipc::JoinSharedListen(p, callback);
         return; // wait for the call back
     }
 
+    StartListeningCb *cbd = dynamic_cast<StartListeningCb*>(callback->getDialer());
+    Must(cbd);
+    cbd->conn = listenConn;
+
     enter_suid();
-    const int sock = comm_open_listener(p.sock_type, p.proto, p.addr, p.flags,
-                                        FdNote(p.fdNote));
-    const int errNo = (sock >= 0) ? 0 : errno;
+    if (sock_type == SOCK_STREAM) {
+        // TCP: setup the subscriptions such that new connections accepted by listenConn are handled by HTTP
+        AsyncJob::Start(new Comm::ConnAcceptor(cbd->conn, FdNote(fdNote), sub));
+    } else if (sock_type == SOCK_DGRAM) {
+        // UDP: setup the listener socket, but do not set a subscriber
+        Comm::ConnectionPointer udpConn = listenConn;
+        comm_open_listener(sock_type, proto, udpConn, FdNote(fdNote));
+    } else {
+        fatalf("Invalid Socket Type (%d)",sock_type);
+    }
+    cbd->errNo = cbd->conn->isOpen() ? 0 : errno;
     leave_suid();
 
-    debugs(54, 3, HERE << "opened listen FD " << sock << " for " << p.addr);
-
-    StartListeningCb *cbd =
-        dynamic_cast<StartListeningCb*>(callback->getDialer());
-    Must(cbd);
-    cbd->fd = sock;
-    cbd->errNo = errNo;
+    debugs(54, 3, HERE << "opened listen " << cbd->conn);
     ScheduleCallHere(callback);
 }
