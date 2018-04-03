     ICAPXaction_Exit();
 }
 
-// HTTP side aborted
-void ICAPModXact::noteSinkAbort(MsgPipe *p)
+// adapted body consumer aborted
+void ICAPModXact::noteBodyConsumerAborted(BodyPipe &)
 {
-    ICAPXaction_Enter(noteSinkAbort);
+    ICAPXaction_Enter(noteBodyConsumerAborted);
 
-    mustStop("HTTP sink quit");
+    mustStop("adapted body consumer aborted");
 
     ICAPXaction_Exit();
 }
 
 // internal cleanup
-void ICAPModXact::doStop()
+void ICAPModXact::swanSong()
 {
-    debugs(93, 5, HERE << "doStop() called");
-    ICAPXaction::doStop();
+    debugs(93, 5, HERE << "swan sings" << status());
+
+    if (initiator) {
+debugs(93, 2, HERE << "swan sings for " << stopReason << status());
+        AsyncCall(93,5, initiator, ICAPInitiator::noteIcapHeadersAborted);
+        cbdataReferenceDone(initiator);
+    }
 
     stopWriting(false);
     stopBackup();
