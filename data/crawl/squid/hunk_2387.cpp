     clientConnection->close();
 }
 
-/** Called to initiate (and possibly complete) closing of the context.
- * The underlying socket may be already closed */
+/// called when we encounter a response-related error
 void
 ClientSocketContext::initiateClose(const char *reason)
 {
-    debugs(33, 5, HERE << "initiateClose: closing for " << reason);
-
-    if (http != NULL) {
-        ConnStateData * conn = http->getConn();
-
-        if (conn != NULL) {
-            if (const int64_t expecting = conn->mayNeedToReadMoreBody()) {
-                debugs(33, 5, HERE << "ClientSocketContext::initiateClose: " <<
-                       "closing, but first " << conn << " needs to read " <<
-                       expecting << " request body bytes with " <<
-                       conn->in.notYetUsed << " notYetUsed");
+    http->getConn()->stopSending(reason); // closes ASAP
+}
 
-                if (conn->closing()) {
-                    debugs(33, 2, HERE << "avoiding double-closing " << conn);
-                    return;
-                }
+void
+ConnStateData::stopSending(const char *error)
+{
+    debugs(33, 4, HERE << "sending error (" << clientConnection << "): " << error <<
+           "; old receiving error: " <<
+           (stoppedReceiving() ? stoppedReceiving_ : "none"));
 
-                /*
-                * XXX We assume the reply fits in the TCP transmit
-                * window.  If not the connection may stall while sending
-                * the reply (before reaching here) if the client does not
-                * try to read the response while sending the request body.
-                * As of yet we have not received any complaints indicating
-                * this may be an issue.
-                */
-                conn->startClosing(reason);
+    if (const char *oldError = stoppedSending()) {
+        debugs(33, 3, HERE << "already stopped sending: " << oldError);
+        return; // nothing has changed as far as this connection is concerned
+    }
+    stoppedSending_ = error;
 
-                return;
-            }
+    if (!stoppedReceiving()) {
+        if (const int64_t expecting = mayNeedToReadMoreBody()) {
+            debugs(33, 5, HERE << "must still read " << expecting <<
+                   " request body bytes with " << in.notYetUsed << " unused");
+            return; // wait for the request receiver to finish reading
         }
     }
 
-    doClose();
+    clientConnection->close();
 }
 
 void
