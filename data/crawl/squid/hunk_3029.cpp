 void
 Comm::ConnAcceptor::doAccept(int fd, void *data)
 {
-    debugs(5, 2, HERE << "New connection on FD " << fd);
+    try {
+        debugs(5, 2, HERE << "New connection on FD " << fd);
 
-    Must(isOpen(fd));
-    ConnAcceptor *afd = static_cast<ConnAcceptor*>(data);
+        Must(isOpen(fd));
+        ConnAcceptor *afd = static_cast<ConnAcceptor*>(data);
 
-    if (!okToAccept()) {
-        AcceptLimiter::Instance().defer(afd);
-    } else {
-        afd->acceptNext();
+        if (!okToAccept()) {
+            AcceptLimiter::Instance().defer(afd);
+        } else {
+            afd->acceptNext();
+        }
+        commSetSelect(fd, COMM_SELECT_READ, Comm::ConnAcceptor::doAccept, afd, 0);
+
+    } catch(TextException &e) {
+        fatalf("FATAL: error while accepting new client connection: %s\n", e.message);
+    } catch(...) {
+        fatal("FATAL: error while accepting new client connection: [unkown]\n");
     }
-    commSetSelect(fd, COMM_SELECT_READ, Comm::ConnAcceptor::doAccept, afd, 0);
 }
 
 bool
