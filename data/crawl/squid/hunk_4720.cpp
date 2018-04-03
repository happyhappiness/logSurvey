         HttpRequest *req = dynamic_cast<HttpRequest*>(adapted->data->header);
 
         if (req) {
-            debugs(32,3,HERE << "notifying body_reader, contentSize() = " << p->data->body->contentSize());
+            debugs(93,3,HERE << "notifying body_reader, contentSize() = " << p->data->body->contentSize());
             req->body_reader->notify(p->data->body->contentSize());
         } else {
             http->takeAdaptedBody(adapted->data->body);
         }
     }
 }
 
-// ICAP client is done sending adapted response
-void ICAPClientReqmodPrecache::noteSourceFinish(MsgPipe *p)
+void ICAPClientReqmodPrecache::tellDoneAdapting()
 {
-    debug(93,3)("ICAPClientReqmodPrecache::noteSourceFinish() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::tellDoneAdapting() called\n");
     //tell ClientHttpRequest that we expect no more response data
-    http->doneAdapting();
+    http->doneAdapting(); // does not delete us (yet?)
     stop(notifyNone);
+    // we should be eventually deleted by owner in ~ClientHttpRequest()
 }
 
-// ICAP client is aborting
-void ICAPClientReqmodPrecache::noteSourceAbort(MsgPipe *p)
+void ICAPClientReqmodPrecache::tellAbortAdapting()
 {
-    debug(93,3)("ICAPClientReqmodPrecache::noteSourceAbort() called\n");
-    stop(notifyOwner);
+    debug(93,3)("ICAPClientReqmodPrecache::tellAbortAdapting() called\n");
+    // tell ClientHttpRequest that we are aborting ICAP processing prematurely
+    http->abortAdapting();
 }
 
 // internal cleanup
 void ICAPClientReqmodPrecache::stop(Notify notify)
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
-#if DONT_FREE_ADAPTED
     /*
      * NOTE: We do not clean up "adapted->sink" here because it may
      * have an HTTP message body that needs to stay around a little
      * while longer so that the HTTP server-side can forward it on.
      */
-    if (adapted != NULL) {
-        if (notify == notifyIcap)
-            adapted->sendSinkAbort();
-        else
-            adapted->sink = NULL;
-
-        freeAdapted();
-    }
-
-#endif
-
-    if (http) {
-        if (notify == notifyOwner)
-            // tell ClientHttpRequest that we are aborting prematurely
-            http->abortAdapting();
 
-        cbdataReferenceDone(http);
+    // XXX: who will clean up the "adapted->sink" then? Does it happen
+    // when the owner deletes us? Is that why we are deleted when the
+    // owner is destroyed and not when ICAP adaptation is done, like
+    // in http.cc case?
 
-        // http is now NULL, will not call it any more
-    }
-}
-
-void ICAPClientReqmodPrecache::freeVirgin()
-{
-    // virgin->data->cause should be NULL;
-    virgin = NULL;	// refcounted
-}
+    // XXX: "adapted->sink" does not really have an "HTTP message body",
+    // In fact, it simply points to "this". Should the above comment
+    // refer to adapted and adapted->data->body?
 
-void ICAPClientReqmodPrecache::freeAdapted()
-{
-    adapted = NULL;	// refcounted
+    ICAPClientVector::clean(notify, false);
 }
 
 /*
