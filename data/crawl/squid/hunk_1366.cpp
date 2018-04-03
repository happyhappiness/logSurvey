     else if (s->flags.tproxyIntercept)
         storeAppendPrintf(e, " tproxy");
 
+    else if (s->flags.proxySurrogate)
+        storeAppendPrintf(e, " proxy-surrogate");
+
     else if (s->flags.accelSurrogate) {
         storeAppendPrintf(e, " accel");
 
