 
 void ICAPXaction::mustStop(const char *aReason)
 {
-    Must(inCall); // otherwise nobody will call doStop()
+    Must(inCall); // otherwise nobody will delete us if we are done()
     Must(aReason);
     if (!stopReason) {
         stopReason = aReason;
