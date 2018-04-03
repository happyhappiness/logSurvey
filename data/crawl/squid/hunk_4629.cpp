         fwd->dontRetry(true);
     }
 
-    debugs(11,5, HERE << "bailing after ICAP failure");
-
-    cleanIcap();
-    closeServer();
-    quitIfAllDone();
+    abortTransaction("ICAP failure");
 }
 
 #endif