         return;
     }
 
-    helperStats(sentry, redirectors, "Redirector Statistics");
+    redirectors->packStatsInto(sentry, "Redirector Statistics");
 
     if (Config.onoff.redirector_bypass)
         storeAppendPrintf(sentry, "\nNumber of requests bypassed "
