 
 // common part of noteIcap*Aborted and noteBodyConsumerAborted methods
 void
-ServerStateData::handleIcapAborted()
+ServerStateData::handleIcapAborted(bool bypassable)
 {
-    debugs(11,5, HERE << "handleIcapAborted; entry empty: " << entry->isEmpty());
+    debugs(11,5, HERE << "handleIcapAborted; bypassable: " << bypassable <<
+        ", entry empty: " << entry->isEmpty());
 
     if (abortOnBadEntry("entry went bad while ICAP aborted"))
         return;
 
+    // TODO: bypass if possible
+
     if (entry->isEmpty()) {
         debugs(11,9, HERE << "creating ICAP error entry after ICAP failure");
         ErrorState *err =
