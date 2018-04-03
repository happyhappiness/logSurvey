     return needToProduce - haveAvailable;
 }
 
-bool
-ConnStateData::closing() const
-{
-    return closing_;
-}
-
-/**
- * Called by ClientSocketContext to give the connection a chance to read
- * the entire body before closing the socket.
- */
 void
-ConnStateData::startClosing(const char *reason)
+ConnStateData::stopReceiving(const char *error)
 {
-    debugs(33, 5, HERE << "startClosing " << this << " for " << reason);
-    assert(!closing());
-    closing_ = true;
+    debugs(33, 4, HERE << "receiving error (" << clientConnection << "): " << error <<
+           "; old sending error: " <<
+           (stoppedSending() ? stoppedSending_ : "none"));
 
-    assert(bodyPipe != NULL);
+    if (const char *oldError = stoppedReceiving()) {
+        debugs(33, 3, HERE << "already stopped receiving: " << oldError);
+        return; // nothing has changed as far as this connection is concerned
+    }
 
-    // We do not have to abort the body pipeline because we are going to
-    // read the entire body anyway.
-    // Perhaps an ICAP server wants to log the complete request.
+    stoppedReceiving_ = error;
 
-    // If a consumer abort have caused this closing, we may get stuck
-    // as nobody is consuming our data. Allow auto-consumption.
-    bodyPipe->enableAutoConsumption();
+    if (const char *sendError = stoppedSending()) {
+        debugs(33, 3, HERE << "closing because also stopped sending: " << sendError);
+        clientConnection->close();
+    }
 }
 
 void
