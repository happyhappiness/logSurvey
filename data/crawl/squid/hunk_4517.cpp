     ICAPXaction_Exit();
 }
 
-// body producer aborted
+// body producer aborted, but the initiator may still want to know 
+// the answer, even though the HTTP message has been truncated
 void ICAPModXact::noteBodyProducerAborted(BodyPipe &)
 {
     ICAPXaction_Enter(noteBodyProducerAborted);
 
-    mustStop("virgin HTTP body producer aborted");
+    Must(virgin.body_pipe->productionEnded());
+
+    // push writer and sender in case we were waiting for the last-chunk
+    writeMore();
+
+    if (state.sending == State::sendingVirgin)
+        echoMore();
 
     ICAPXaction_Exit();
 }
