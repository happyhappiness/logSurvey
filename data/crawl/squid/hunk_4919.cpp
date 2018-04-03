 }
 
 // ICAP client is done sending adapted response
-void ICAPAnchor::noteSourceFinish(MsgPipe *p)
+void ICAPClientRespmodPrecache::noteSourceFinish(MsgPipe *p)
 {
-    debug(93,5)("ICAPAnchor::noteSourceFinish() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::noteSourceFinish() called\n");
     //tell HttpStateData that we expect no more response data
     leakTouch(p, MsgPipeLeaker);
     httpState->doneAdapting();
     stop(notifyNone);
 }
 
 // ICAP client is aborting
-void ICAPAnchor::noteSourceAbort(MsgPipe *p)
+void ICAPClientRespmodPrecache::noteSourceAbort(MsgPipe *p)
 {
-    debug(93,5)("ICAPAnchor::noteSourceAbort() called\n");
+    debug(93,5)("ICAPClientRespmodPrecache::noteSourceAbort() called\n");
     leakTouch(p, MsgPipeLeaker);
     stop(notifyOwner);
 }
 
 // internal cleanup
-void ICAPAnchor::stop(Notify notify)
+void ICAPClientRespmodPrecache::stop(Notify notify)
 {
     if (virgin != NULL) {
         leakTouch(virgin.getRaw(), MsgPipeLeaker);
