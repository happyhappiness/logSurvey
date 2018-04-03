     storeAppendPrintf(sentry,
 	"{Swap-Low %d \"# Low water mark disk cache (%%)\"}\n",
 	Config.Swap.lowWaterMark);
-    storeAppendPrintf(sentry,
-	"{HTTP-Max %d\"# Maximum size HTTP objects (KB)\"}\n",
-	Config.Http.maxObjSize / (1 << 10));
-    storeAppendPrintf(sentry,
-	"{HTTP-TTL %d \"# Http object default TTL (hrs)\"}\n",
-	Config.Http.defaultTtl / 3600);
-    storeAppendPrintf(sentry,
-	"{Gopher-Max %d \"# Maximum size gopher objects (KB)\"}\n",
-	Config.Gopher.maxObjSize / (1 << 10));
-    storeAppendPrintf(sentry,
-	"{Gopher-TTL %d \"# TTL for gopher objects (hrs)\"}\n",
-	Config.Gopher.defaultTtl / 3600);
-    storeAppendPrintf(sentry,
-	"{FTP-Max %d \"# Maximum size FTP objects (KB)\"}\n",
-	Config.Ftp.maxObjSize / (1 << 10));
-    storeAppendPrintf(sentry,
-	"{FTP-TTL %d \"# TTL for FTP objects (hrs)\"}\n",
-	Config.Ftp.defaultTtl / 3600);
     storeAppendPrintf(sentry,
 	"{Neg-TTL %d \"# TTL for negative cache (s)\"}\n",
 	Config.negativeTtl);
