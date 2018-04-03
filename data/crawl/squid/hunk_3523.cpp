 }
 
 void
-ClientSocketContext::writeComplete(int fd, char *bufnotused, size_t size, comm_err_t errflag)
+ClientSocketContext::writeComplete(int aFileDescriptor, char *bufnotused, size_t size, comm_err_t errflag)
 {
     StoreEntry *entry = http->storeEntry();
     http->out.size += size;
-    assert(fd > -1);
-    debugs(33, 5, "clientWriteComplete: FD " << fd << ", sz " << size <<
+    assert(aFileDescriptor > -1);
+    debugs(33, 5, "clientWriteComplete: FD " << aFileDescriptor << ", sz " << size <<
            ", err " << errflag << ", off " << http->out.size << ", len " <<
            entry ? entry->objectLen() : 0);
     clientUpdateSocketStats(http->logType, size);
-    assert (this->fd() == fd);
+    assert (this->fd() == aFileDescriptor);
 
     /* Bail out quickly on COMM_ERR_CLOSING - close handlers will tidy up */
 
     if (errflag == COMM_ERR_CLOSING)
         return;
 
-    if (errflag || clientHttpRequestStatus(fd, http)) {
+    if (errflag || clientHttpRequestStatus(aFileDescriptor, http)) {
         initiateClose("failure or true request status");
         /* Do we leak here ? */
         return;
