         return;
     }
 
-    storeAppendPrintf(sentry, "Redirector Statistics:\n");
-    helperStats(sentry, redirectors);
+    helperStats(sentry, redirectors, "Redirector Statistics");
 
     if (Config.onoff.redirector_bypass)
         storeAppendPrintf(sentry, "\nNumber of requests bypassed "