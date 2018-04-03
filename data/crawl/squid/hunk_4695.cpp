 }
 
 void
-ClientSocketContext::initiateClose()
+ClientSocketContext::initiateClose(const char *reason)
 {
+    debugs(33, 5, HERE << "initiateClose: closing for " << reason);
     if (http != NULL) {
         ConnStateData::Pointer conn = http->getConn();
 
         if (conn != NULL) {
-            if (conn->bodySizeLeft() > 0) {
-                debug(33, 5) ("ClientSocketContext::initiateClose: closing, but first we need to read the rest of the request\n");
+            if (const ssize_t expecting = conn->bodySizeLeft()) {
+                debugs(33, 5, HERE << "ClientSocketContext::initiateClose: " <<
+                       "closing, but first " << conn << " needs to read " <<
+                       expecting << " request body bytes with " <<
+                       conn->in.notYetUsed << " notYetUsed");
+
+                if (conn->closing()) {
+                    debugs(33, 2, HERE << "avoiding double-closing " << conn);
+                    return;
+                }
+                    
                 /*
                 * XXX We assume the reply fits in the TCP transmit
                 * window.  If not the connection may stall while sending
