         return;
 
     if (state.sending != State::sendingUndecided) {
-        debugs(93, 7, "ICAPModXact will no longer send " << status());
-
-        if (nicely)
-            adapted->sendSourceFinish();
-        else
-            adapted->sendSourceAbort();
+        debugs(93, 7, "ICAPModXact will no longer send" << status());
+        if (adapted.body_pipe != NULL) {
+            virginBodySending.disable();
+            // we may leave debts if we were echoing and the virgin
+            // body_pipe got exhausted before we echoed all planned bytes
+            const bool leftDebts = adapted.body_pipe->needsMoreData();
+            stopProducingFor(adapted.body_pipe, nicely && !leftDebts);
+        }
     } else {
-        debugs(93, 7, "ICAPModXact will not start sending " << status());
-        adapted->sendSourceAbort(); // or the sink may wait forever
+        debugs(93, 7, "ICAPModXact will not start sending" << status());
+        Must(!adapted.body_pipe);
     }
 
     state.sending = State::sendingDone;
-
-    adapted = NULL; // refcounted
+    checkConsuming();
 }
 
-void ICAPModXact::stopReceiving()
+// should be called after certain state.writing or state.sending changes
+void ICAPModXact::checkConsuming()
 {
-    // stopSending NULLifies adapted but we do not NULLify virgin.
-    // This is assymetric because we want to keep virgin->data even
-    // though we are not expecting any more virgin->data->body.
-    // TODO: can we cache just the needed headers info instead?
-
-    // If they closed first, there is not point (or means) to notify them.
-
-    if (state.doneReceiving)
+    // quit if we already stopped or are still using the pipe
+    if (!virgin.body_pipe || !state.doneConsumingVirgin())
         return;
 
-    // There is no sendSinkFinished() to notify the other side.
-    debugs(93, 7, "ICAPModXact will not receive " << status());
-
-    state.doneReceiving = true;
+    debugs(93, 7, HERE << "will stop consuming" << status());
+    stopConsumingFrom(virgin.body_pipe);
 }
 
 void ICAPModXact::parseMore()
