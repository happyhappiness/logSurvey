     if (commBuf)
         memFreeBuf(commBufSize, commBuf);
 
-    debugs(93, 5, HERE << "swan sang" << status());
-}
-
-void ICAPXaction::service(ICAPServiceRep::Pointer &aService)
-{
-    Must(!theService);
-    Must(aService != NULL);
-    theService = aService;
-}
-
-ICAPServiceRep &ICAPXaction::service()
-{
-    Must(theService != NULL);
-    return *theService;
-}
-
-bool ICAPXaction::callStart(const char *method)
-{
-    debugs(93, 5, typeName << "::" << method << " called" << status());
-
-    if (inCall) {
-        // this may happen when we have bugs or when arguably buggy
-        // comm interface calls us while we are closing the connection
-        debugs(93, 5, HERE << typeName << "::" << inCall <<
-               " is in progress; " << typeName << "::" << method <<
-               " cancels reentry.");
-        return false;
-    }
-
-    if (!self) {
-        // this may happen when swanSong() has not properly cleaned up.
-        debugs(93, 5, HERE << typeName << "::" << method <<
-               " is not admitted to a finished transaction " << this);
-        return false;
-    }
-
-    inCall = method;
-    return true;
-}
-
-void ICAPXaction::callException(const TextException &e)
-{
-    debugs(93, 2, typeName << "::" << inCall << " caught an exception: " <<
-           e.message << ' ' << status());
-
-    reuseConnection = false; // be conservative
-    mustStop("exception");
-}
-
-void ICAPXaction::callEnd()
-{
-    if (done()) {
-        debugs(93, 5, typeName << "::" << inCall << " ends xaction " <<
-            status());
-        swanSong();
-        const char *inCallSaved = inCall;
-        const char *typeNameSaved = typeName;
-        inCall = NULL;
-        self = NULL; // will delete us, now or eventually
-        debugs(93, 6, HERE << typeNameSaved << "::" << inCallSaved <<
-            " ended " << this);
-        return;
-    } else
-    if (doneWithIo()) {
-        debugs(93, 5, HERE << typeName << " done with I/O" << status());
-        closeConnection();
-    }
+    if (theInitiator)
+        tellQueryAborted(!isRetriable);
 
-    debugs(93, 6, typeName << "::" << inCall << " ended" << status());
-    inCall = NULL;
+    ICAPInitiate::swanSong();
 }
 
 // returns a temporary string depicting transaction status, for debugging
