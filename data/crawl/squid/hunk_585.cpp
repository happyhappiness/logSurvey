 // premature end of the adapted response body
 void Client::handleAdaptedBodyProducerAborted()
 {
+    if (abortOnBadEntry("entry went bad while waiting for the now-aborted adapted body"))
+        return;
+
+    Must(adaptedBodySource != nullptr);
+    if (!adaptedBodySource->exhausted()) {
+        debugs(11,5, "waiting to consume the remainder of the aborted adapted body");
+        return; // resumeBodyStorage() should eventually consume the rest
+    }
+
     stopConsumingFrom(adaptedBodySource);
-    handleAdaptationAborted();
+
+    if (handledEarlyAdaptationAbort())
+        return;
+
+    entry->lengthWentBad("body adaptation aborted");
+    handleAdaptationCompleted(); // the user should get a truncated response
 }
 
 // common part of noteAdaptationAnswer and handleAdaptedBodyProductionEnded
