 
 void AsyncJob::noteStart()
 {
-    AsyncCallEnter(noteStart);
-
     start();
-
-    AsyncCallExit();
 }
 
 void AsyncJob::start()
 {
-    Must(cbdataReferenceValid(this)); // locked in AsyncStart
+}
+
+// XXX: temporary code to replace calls to "delete this" in jobs-in-transition.
+// Will be replaced with calls to mustStop() when transition is complete.
+void AsyncJob::deleteThis(const char *aReason)
+{
+    Must(aReason);
+    stopReason = aReason;
+    if (inCall != NULL) {
+        // if we are in-call, then the call wrapper will delete us
+        debugs(93, 4, typeName << " will NOT delete in-call job, reason: " << stopReason);
+        return;
+	}
+    
+    // there is no call wrapper waiting for our return, so we fake it
+    debugs(93, 5, typeName << " will delete this, reason: " << stopReason);
+    AsyncCall::Pointer fakeCall = asyncCall(93,4, "FAKE-deleteThis",
+        MemFun(this, &AsyncJob::deleteThis, aReason));
+    inCall = fakeCall;
+    callEnd();
+//    delete fakeCall;
 }
 
 void AsyncJob::mustStop(const char *aReason)
 {
-    Must(inCall); // otherwise nobody will delete us if we are done()
+    // XXX: temporary code to catch cases where mustStop is called outside
+    // of an async call context. Will be removed when that becomes impossible.
+    // Until then, this will cause memory leaks and possibly other problems.
+    if (!inCall) { 
+        stopReason = aReason;
+        debugs(93, 5, typeName << " will STALL, reason: " << stopReason);
+        return;
+	}
+
+    Must(inCall != NULL); // otherwise nobody will delete us if we are done()
     Must(aReason);
     if (!stopReason) {
         stopReason = aReason;
