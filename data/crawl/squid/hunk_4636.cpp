         doneReading() && doneWriting();
 }
 
-void ICAPXaction::mustStop(const char *aReason)
+// initiator aborted
+void ICAPXaction::noteInitiatorAborted()
 {
-    Must(inCall); // otherwise nobody will delete us if we are done()
-    Must(aReason);
-    if (!stopReason) {
-        stopReason = aReason;
-        debugs(93, 5, typeName << " will stop, reason: " << stopReason);
-    } else {
-        debugs(93, 5, typeName << " will stop, another reason: " << aReason);
+    ICAPXaction_Enter(noteInitiatorAborted);
+
+    if (theInitiator) {
+        clearInitiator();
+        mustStop("initiator aborted");
     }
+
+    ICAPXaction_Exit();
 }
 
 // This 'last chance' method is called before a 'done' transaction is deleted.
