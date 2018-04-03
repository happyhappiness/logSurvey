     if (io.flag == COMM_ERR_CLOSING)
         return;
 
-    assert(io.fd == data.fd);
+    assert(io.fd == data.conn->fd);
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
         abortTransaction("entry aborted during dataRead");
