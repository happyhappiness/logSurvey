 
 #if DELAY_POOLS
 
-        storeAppendPrintf(s, "delay_pool %d\n", DelayId::DelayClient(http) >> 16);
+        storeAppendPrintf(s, "delay_pool %d\n", DelayId::DelayClient(http).pool());
 
 #endif
 