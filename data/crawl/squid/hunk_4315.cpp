 }
 
 
-// common part of noteIcap*Aborted and noteBodyConsumerAborted methods
+// common part of noteAdaptation*Aborted and noteBodyConsumerAborted methods
 void
-ServerStateData::handleIcapAborted(bool bypassable)
+ServerStateData::handleAdaptationAborted(bool bypassable)
 {
-    debugs(11,5, HERE << "handleIcapAborted; bypassable: " << bypassable <<
+    debugs(11,5, HERE << "handleAdaptationAborted; bypassable: " << bypassable <<
         ", entry empty: " << entry->isEmpty());
 
     if (abortOnBadEntry("entry went bad while ICAP aborted"))
