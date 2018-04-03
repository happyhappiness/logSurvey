     }
 
     fwd->handleUnregisteredServerEnd();
-    deleteThis("FtpStateData::abortTransaction");
+    mustStop("FtpStateData::abortTransaction");
 }
 
 /// creates a data channel Comm close callback
