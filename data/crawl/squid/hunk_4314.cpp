     if (abortOnBadEntry("entry went bad while waiting for adapted body eof"))
         return;
 
-    handleIcapCompleted();
+    handleAdaptationCompleted();
 }
 
 // premature end of the adapted response body
 void ServerStateData::handleAdaptedBodyProducerAborted()
 {
     stopConsumingFrom(adaptedBodySource);
-    handleIcapAborted();
+    handleAdaptationAborted();
 }
 
-// common part of noteIcapAnswer and handleAdaptedBodyProductionEnded
+// common part of noteAdaptationAnswer and handleAdaptedBodyProductionEnded
 void
-ServerStateData::handleIcapCompleted()
+ServerStateData::handleAdaptationCompleted()
 {
-    debugs(11,5, HERE << "handleIcapCompleted");
-    cleanIcap();
+    debugs(11,5, HERE << "handleAdaptationCompleted");
+    cleanAdaptation();
 
     // We stop reading origin response because we have no place to put it and
     // cannot use it. If some origin servers do not like that or if we want to
