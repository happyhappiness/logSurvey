         return;
 
     // TODO: bypass if possible
+    if (!handledEarlyAdaptationAbort())
+        abortTransaction("adaptation failure with a filled entry");
+}
 
+/// If the store entry is still empty, fully handles adaptation abort, returning
+/// true. Otherwise just updates the request error detail and returns false.
+bool
+Client::handledEarlyAdaptationAbort()
+{
     if (entry->isEmpty()) {
-        debugs(11,9, HERE << "creating ICAP error entry after ICAP failure");
+        debugs(11,8, "adaptation failure with an empty entry: " << *entry);
         ErrorState *err = new ErrorState(ERR_ICAP_FAILURE, Http::scInternalServerError, request);
         err->detailError(ERR_DETAIL_ICAP_RESPMOD_EARLY);
         fwd->fail(err);
         fwd->dontRetry(true);
-    } else if (request) { // update logged info directly
-        request->detailError(ERR_ICAP_FAILURE, ERR_DETAIL_ICAP_RESPMOD_LATE);
+        abortTransaction("adaptation failure with an empty entry");
+        return true; // handled
     }
 
-    abortTransaction("ICAP failure");
+    if (request) // update logged info directly
+        request->detailError(ERR_ICAP_FAILURE, ERR_DETAIL_ICAP_RESPMOD_LATE);
+
+    return false; // the caller must handle
 }
 
 // adaptation service wants us to deny HTTP client access to this response
