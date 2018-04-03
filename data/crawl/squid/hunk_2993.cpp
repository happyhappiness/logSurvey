     if (errflag == COMM_ERR_CLOSING)
         return;
 
-    assert (Comm::IsConnOpen(http->getConn()->clientConn) && this->fd() == aFileDescriptor);
+    assert(Comm::IsConnOpen(clientConn()) && clientConn()->fd == conn->fd);
 
-    if (errflag || clientHttpRequestStatus(aFileDescriptor, http)) {
+    if (errflag || clientHttpRequestStatus(conn->fd, http)) {
         initiateClose("failure or true request status");
         /* Do we leak here ? */
         return;
