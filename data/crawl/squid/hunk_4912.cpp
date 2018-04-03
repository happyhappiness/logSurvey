 }
 
 // ClientHttpRequest says we have the entire HTTP message
-void ICAPClientSideHook::doneSending()
+void ICAPClientReqmodPrecache::doneSending()
 {
-    debug(93,3)("ICAPClientSideHook::doneSending() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::doneSending() called\n");
     leakTouch(virgin.getRaw(), MsgPipeLeaker);
 
     virgin->sendSourceFinish();
 }
 
 // ClientHttpRequest tells us to abort
-void ICAPClientSideHook::ownerAbort()
+void ICAPClientReqmodPrecache::ownerAbort()
 {
-    debug(93,3)("ICAPClientSideHook::ownerAbort() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::ownerAbort() called\n");
     stop(notifyIcap);
 }
 
 // ICAP client needs more virgin response data
-void ICAPClientSideHook::noteSinkNeed(MsgPipe *p)
+void ICAPClientReqmodPrecache::noteSinkNeed(MsgPipe *p)
 {
-    debug(93,3)("ICAPClientSideHook::noteSinkNeed() called\n");
+    debug(93,3)("ICAPClientReqmodPrecache::noteSinkNeed() called\n");
 
     leakTouch(virgin.getRaw(), MsgPipeLeaker);
 
