 void 
 Ecap::XactionRep::adaptationAborted()
 {
-    theMaster.reset();
     tellQueryAborted(true); // should eCAP support retries?
+    mustStop("adaptationAborted");
 }
 
 bool
