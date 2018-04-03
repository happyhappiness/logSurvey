     assert(io.fd == data.conn->fd);
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        abortTransaction("entry aborted during dataRead");
+        abortOnData("entry aborted during dataRead");
         return;
     }
 
