 }
 
 void
-ClientSocketContext::writeComplete(const Comm::ConnectionPointer &conn, char *, size_t size, Comm::Flag errflag)
+ConnStateData::afterClientWrite(size_t size)
+{
+    if (pipeline.empty())
+        return;
+
+    pipeline.front()->writeComplete(size);
+}
+
+// TODO: make this only need size parameter, ConnStateData handles the rest
+void
+ClientSocketContext::writeComplete(size_t size)
 {
     const StoreEntry *entry = http->storeEntry();
-    http->out.size += size;
-    debugs(33, 5, HERE << conn << ", sz " << size <<
-           ", err " << errflag << ", off " << http->out.size << ", len " <<
+    debugs(33, 5, clientConnection << ", sz " << size <<
+           ", off " << (http->out.size + size) << ", len " <<
            (entry ? entry->objectLen() : 0));
-    clientUpdateSocketStats(http->logType, size);
 
-    /* Bail out quickly on Comm::ERR_CLOSING - close handlers will tidy up */
-
-    if (errflag == Comm::ERR_CLOSING || !Comm::IsConnOpen(conn))
-        return;
+    http->out.size += size;
+    clientUpdateSocketStats(http->logType, size);
 
-    if (errflag || clientHttpRequestStatus(conn->fd, http)) {
+    if (clientHttpRequestStatus(clientConnection->fd, http)) {
         initiateClose("failure or true request status");
         /* Do we leak here ? */
         return;
