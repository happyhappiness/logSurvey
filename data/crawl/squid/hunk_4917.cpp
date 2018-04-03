 }
 
 // HttpStateData tells us to abort
-void ICAPAnchor::ownerAbort()
+void ICAPClientRespmodPrecache::ownerAbort()
 {
-    debug(93,5)("ICAPAnchor::ownerAbort() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::ownerAbort() called\n");
     stop(notifyIcap);
 }
 
 // ICAP client needs more virgin response data
-void ICAPAnchor::noteSinkNeed(MsgPipe *p)
+void ICAPClientRespmodPrecache::noteSinkNeed(MsgPipe *p)
 {
-    debug(93,5)("ICAPAnchor::noteSinkNeed() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::noteSinkNeed() called\n");
 
     leakTouch(virgin.getRaw(), MsgPipeLeaker);
 
