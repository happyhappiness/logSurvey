 // ICAP client sends more data
 void ICAPClientRespmodPrecache::noteSourceProgress(MsgPipe *p)
 {
-    debug(93,5)("ICAPClientRespmodPrecache::noteSourceProgress() called\n");
+    debug(93,3)("ICAPClientRespmodPrecache::noteSourceProgress() called\n");
     //tell ServerStateData to store a fresh portion of the adapted response
 
     assert(serverState);
 
     if (p->data->body->hasContent()) {
-        serverState->takeAdaptedBody(p->data->body);
-    }
-}
+        if (!serverState->takeAdaptedBody(p->data->body))
+            return;
 
-// ICAP client is done sending adapted response
-void ICAPClientRespmodPrecache::noteSourceFinish(MsgPipe *p)
-{
-    debug(93,5)("ICAPClientRespmodPrecache::noteSourceFinish() called\n");
-    //tell ServerStateData that we expect no more response data
-    serverState->doneAdapting();
-    stop(notifyNone);
+        // HttpStateData::takeAdaptedBody does not detect when we have enough,
+        // so we always notify source that there more buffer space is available
+        if (p->data->body->hasPotentialSpace())
+            adapted->sendSinkNeed(); 
+    }
 }
 
-// ICAP client is aborting
-void ICAPClientRespmodPrecache::noteSourceAbort(MsgPipe *p)
+void
+ICAPClientRespmodPrecache::tellSpaceAvailable()
 {
-    debug(93,5)("ICAPClientRespmodPrecache::noteSourceAbort() called\n");
-    stop(notifyOwner);
+    serverState->icapSpaceAvailable();
 }
 
-// internal cleanup
-void ICAPClientRespmodPrecache::stop(Notify notify)
+void
+ICAPClientRespmodPrecache::tellDoneAdapting()
 {
-    if (virgin != NULL) {
-        if (notify == notifyIcap)
-            virgin->sendSourceAbort();
-        else
-            virgin->source = NULL;
-
-        freeVirgin();
-    }
-
-    if (adapted != NULL) {
-        if (notify == notifyIcap)
-            adapted->sendSinkAbort();
-        else
-            adapted->sink = NULL;
-
-        freeAdapted();
-    }
-
-    if (serverState) {
-        if (notify == notifyOwner)
-            // tell ServerStateData that we are aborting prematurely
-            serverState->abortAdapting();
-
-        cbdataReferenceDone(serverState);
-
-        // serverState is now NULL, will not call it any more
-    }
+    serverState->finishAdapting(); // deletes us
 }
 
-void ICAPClientRespmodPrecache::freeVirgin()
+void
+ICAPClientRespmodPrecache::tellAbortAdapting()
 {
-    virgin = NULL;	// refcounted
+    debug(93,3)("ICAPClientReqmodPrecache::tellAbortAdapting() called\n");
+    // tell ClientHttpRequest that we are aborting ICAP processing prematurely
+    serverState->abortAdapting(); // deletes us
 }
 
-void ICAPClientRespmodPrecache::freeAdapted()
-{
-    adapted = NULL;	// refcounted
-}
