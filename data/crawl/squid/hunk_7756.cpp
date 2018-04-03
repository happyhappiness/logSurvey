 
     memset(line, '\0', MAX_LINELEN);
 
-    storeAppendPrintf(sentry, "{\n");
+    storeAppendPrintf(sentry, open_bracket);
 
     storeAppendPrintf(sentry, "{VM-Max %d \"# Maximum hot-vm cache (MB)\"}\n",
 	getCacheMemMax() / (1 << 20));
