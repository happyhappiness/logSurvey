 }
 
 // HTTP side sent us all virgin info
-void ICAPModXact::noteSourceFinish(MsgPipe *p)
+void ICAPModXact::noteBodyProductionEnded(BodyPipe &)
 {
-    ICAPXaction_Enter(noteSourceFinish);
+    ICAPXaction_Enter(noteBodyProductionEnded);
 
-    Must(!state.doneReceiving);
-    stopReceiving();
+    Must(virgin.body_pipe->productionEnded());
 
     // push writer and sender in case we were waiting for the last-chunk
     writeMore();
