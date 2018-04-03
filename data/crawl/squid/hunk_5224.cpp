 {
     dlink_node *i;
     clientHttpRequest *http;
-    ConnStateData *conn;
     StoreEntry *e;
     int fd;
 
     for (i = ClientActiveRequests.head; i; i = i->next) {
         http = static_cast<clientHttpRequest *>(i->data);
         assert(http);
-        conn = http->getConn();
-        storeAppendPrintf(s, "Connection: %p\n", conn);
+        ConnStateData::Pointer conn = http->getConn();
+        storeAppendPrintf(s, "Connection: %p\n", conn.getRaw());
 
-        if (conn) {
+        if (conn.getRaw() != NULL) {
             fd = conn->fd;
             storeAppendPrintf(s, "\tFD %d, read %d, wrote %d\n", fd,
                               fd_table[fd].bytes_read, fd_table[fd].bytes_written);
