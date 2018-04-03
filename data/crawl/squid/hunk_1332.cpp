 bool
 ConnStateData::proxyProtocolError(const char *msg)
 {
-    if (msg)
+    if (msg) {
+        debugs(33, 2, msg << " from " << clientConnection);
         mustStop(msg);
+    }
     return false;
 }
 
