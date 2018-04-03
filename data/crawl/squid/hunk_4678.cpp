     ICAPXaction_Exit();
 }
 
-// HTTP side is aborting
-void ICAPModXact::noteSourceAbort(MsgPipe *p)
+// body producer aborted
+void ICAPModXact::noteBodyProducerAborted(BodyPipe &)
 {
-    ICAPXaction_Enter(noteSourceAbort);
+    ICAPXaction_Enter(noteBodyProducerAborted);
+
+    mustStop("virgin HTTP body producer aborted");
 
-    Must(!state.doneReceiving);
-    stopReceiving();
-    mustStop("HTTP source quit");
+    ICAPXaction_Exit();
+}
+
+// initiator aborted
+void ICAPModXact::noteInitiatorAborted()
+{
+    ICAPXaction_Enter(noteInitiatorAborted);
+
+    if (initiator) {
+        cbdataReferenceDone(initiator);
+        mustStop("initiator aborted");
+    }
 
     ICAPXaction_Exit();
 }
 
-// HTTP side wants more adapted data and possibly freed some buffer space
-void ICAPModXact::noteSinkNeed(MsgPipe *p)
+// adapted body consumer wants more adapted data and 
+// possibly freed some buffer space
+void ICAPModXact::noteMoreBodySpaceAvailable(BodyPipe &)
 {
-    ICAPXaction_Enter(noteSinkNeed);
+    ICAPXaction_Enter(noteMoreBodySpaceAvailable);
 
     if (state.sending == State::sendingVirgin)
         echoMore();
