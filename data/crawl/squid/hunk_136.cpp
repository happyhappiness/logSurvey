 {
     debugs(9, 3, HERE);
 
-    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        abortAll("entry aborted when accepting data conn");
-        data.listenConn->close();
-        data.listenConn = NULL;
+    if (!Comm::IsConnOpen(ctrl.conn)) { /*Close handlers will cleanup*/
+        debugs(9, 5, "The control connection to the remote end is closed");
         return;
     }
 
