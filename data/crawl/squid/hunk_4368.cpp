         const char *p = NULL;
         http = static_cast<ClientHttpRequest *>(i->data);
         assert(http);
-        ConnStateData::Pointer conn = http->getConn();
-        storeAppendPrintf(s, "Connection: %p\n", conn.getRaw());
+        ConnStateData * conn = http->getConn();
+        storeAppendPrintf(s, "Connection: %p\n", conn);
 
         if (conn != NULL) {
             fd = conn->fd;