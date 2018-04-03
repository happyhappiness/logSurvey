         storeAppendPrintf(e, " tproxy");
 
     else if (s->flags.proxySurrogate)
-        storeAppendPrintf(e, " proxy-surrogate");
+        storeAppendPrintf(e, " require-proxy-header");
 
     else if (s->flags.accelSurrogate) {
         storeAppendPrintf(e, " accel");
