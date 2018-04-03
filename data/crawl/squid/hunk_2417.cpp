     }
 
     fwd->handleUnregisteredServerEnd();
-    deleteThis("HttpStateData::abortTransaction");
+    mustStop("HttpStateData::abortTransaction");
 }
