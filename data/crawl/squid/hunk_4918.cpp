 }
 
 // ICAP client aborting
-void ICAPAnchor::noteSinkAbort(MsgPipe *p)
+void ICAPClientRespmodPrecache::noteSinkAbort(MsgPipe *p)
 {
-    debug(93,5)("ICAPAnchor::noteSinkAbort() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::noteSinkAbort() called\n");
     stop(notifyOwner);
 }
 
 // ICAP client starts sending adapted response
 // ICAP client has received new HTTP headers (if any) at this point
-void ICAPAnchor::noteSourceStart(MsgPipe *p)
+void ICAPClientRespmodPrecache::noteSourceStart(MsgPipe *p)
 {
-    debug(93,5)("ICAPAnchor::noteSourceStart() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::noteSourceStart() called\n");
     leakTouch(adapted.getRaw(), MsgPipeLeaker);
 
     HttpReply *reply = dynamic_cast<HttpReply*>(adapted->data->header);
