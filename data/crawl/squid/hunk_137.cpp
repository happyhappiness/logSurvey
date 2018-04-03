         return;
     }
 
+    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
+        abortAll("entry aborted when accepting data conn");
+        data.listenConn->close();
+        data.listenConn = NULL;
+        io.conn->close();
+        return;
+    }
+
     /* data listening conn is no longer even open. abort. */
     if (!Comm::IsConnOpen(data.listenConn)) {
         data.listenConn = NULL; // ensure that it's cleared and not just closed.
