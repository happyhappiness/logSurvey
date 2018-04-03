 
 void ICAPXaction::handleCommTimedout()
 {
-    debugs(93, 0, HERE << "ICAP FD " << connection << " timeout to " << theService->methodStr() << " " << theService->uri.buf());
+    debugs(93, 2, HERE << typeName << " timeout with " <<
+        theService->methodStr() << " " << theService->uri.buf() << status());
     reuseConnection = false;
-    MemBuf mb;
-    mb.init();
-
-    if (fillVirginHttpHeader(mb)) {
-        debugs(93, 0, HERE << "\tfor " << mb.content());
-    }
+    service().noteFailure();
 
-    mustStop("connection with ICAP service timed out");
+    throw TexcHere(connector ?
+        "timed out while connecting to the ICAP service" :
+        "timed out while talking to the ICAP service");
 }
 
 // unexpected connection close while talking to the ICAP service
