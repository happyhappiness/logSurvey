 }
 
 // ICAP client aborting
-void ICAPClientSideHook::noteSinkAbort(MsgPipe *p)
+void ICAPClientReqmodPrecache::noteSinkAbort(MsgPipe *p)
 {
-    debug(93,3)("ICAPClientSideHook::noteSinkAbort() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::noteSinkAbort() called\n");
     stop(notifyOwner);
 }
 
 // ICAP client starts sending adapted response
 // ICAP client has received new HTTP headers (if any) at this point
-void ICAPClientSideHook::noteSourceStart(MsgPipe *p)
+void ICAPClientReqmodPrecache::noteSourceStart(MsgPipe *p)
 {
-    debug(93,3)("ICAPClientSideHook::noteSourceStart() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::noteSourceStart() called\n");
     leakTouch(adapted.getRaw(), MsgPipeLeaker);
     http->takeAdaptedHeaders(adapted->data->header);
     noteSourceProgress(p);
 }
 
 // ICAP client sends more data
-void ICAPClientSideHook::noteSourceProgress(MsgPipe *p)
+void ICAPClientReqmodPrecache::noteSourceProgress(MsgPipe *p)
 {
-    debug(93,3)("ICAPClientSideHook::noteSourceProgress() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::noteSourceProgress() called\n");
     //tell ClientHttpRequest to store a fresh portion of the adapted response
 
     leakTouch(p, MsgPipeLeaker);
