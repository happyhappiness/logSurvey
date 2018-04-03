         return;
     }
 
-    helperStats(sentry, storeIds, "StoreId helper Statistics");
+    storeIds->packStatsInto(sentry, "StoreId helper Statistics");
 
     if (Config.onoff.store_id_bypass)
         storeAppendPrintf(sentry, "\nNumber of requests bypassed "
