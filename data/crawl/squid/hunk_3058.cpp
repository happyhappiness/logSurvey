 void Adaptation::Icap::Xaction::noteInitiatorAborted()
 {
 
-    if (theInitiator) {
+    if (theInitiator.set()) {
         clearInitiator();
         mustStop("initiator aborted");
     }