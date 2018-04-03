  * done later when enough sockets become available.
  */
 void
-Comm::ListenStateData::doAccept(int fd, void *data)
+Comm::TcpAcceptor::doAccept(int fd, void *data)
 {
-    debugs(5, 2, HERE << "New connection on FD " << fd);
+    try {
+        debugs(5, 2, HERE << "New connection on FD " << fd);
 
-    assert(isOpen(fd));
-    ListenStateData *afd = static_cast<ListenStateData*>(data);
+        Must(isOpen(fd));
+        TcpAcceptor *afd = static_cast<TcpAcceptor*>(data);
+
+        if (!okToAccept()) {
+            AcceptLimiter::Instance().defer(afd);
+        } else {
+            afd->acceptNext();
+        }
+        SetSelect(fd, COMM_SELECT_READ, Comm::TcpAcceptor::doAccept, afd, 0);
 
-    if (!okToAccept()) {
-        AcceptLimiter::Instance().defer(afd);
-    } else {
-        afd->acceptNext();
+    } catch (const std::exception &e) {
+        fatalf("FATAL: error while accepting new client connection: %s\n", e.what());
+    } catch (...) {
+        fatal("FATAL: error while accepting new client connection: [unkown]\n");
     }
-    SetSelect(fd, COMM_SELECT_READ, Comm::ListenStateData::doAccept, afd, 0);
 }
 
 bool
-Comm::ListenStateData::okToAccept()
+Comm::TcpAcceptor::okToAccept()
 {
     static time_t last_warn = 0;
 
