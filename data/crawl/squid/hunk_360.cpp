     Client::sentRequestBody(io);
 }
 
-// Quickly abort the transaction
-// TODO: destruction should be sufficient as the destructor should cleanup,
-// including canceling close handlers
 void
 HttpStateData::abortAll(const char *reason)
 {
     debugs(11,5, HERE << "aborting transaction for " << reason <<
            "; " << serverConnection << ", this " << this);
-
-    if (Comm::IsConnOpen(serverConnection)) {
-        serverConnection->close();
-        return;
-    }
-
-    fwd->handleUnregisteredServerEnd();
-    mustStop("HttpStateData::abortAll");
+    mustStop(reason);
 }
 