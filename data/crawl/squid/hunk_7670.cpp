     storeAppendPrintf(sentry, open_bracket);
     storeAppendPrintf(sentry,
 	"{VM-Max %d \"# Maximum hot-vm cache (MB)\"}\n",
-	getCacheMemMax() / (1 << 20));
+	Config.Mem.maxSize / (1 << 20));
     storeAppendPrintf(sentry,
 	"{VM-High %d \"# High water mark hot-vm cache (%%)\"}\n",
-	getCacheMemHighWaterMark());
+	Config.Mem.highWaterMark);
     storeAppendPrintf(sentry,
 	"{VM-Low %d \"# Low water-mark hot-vm cache (%%)\"}\n",
-	getCacheMemLowWaterMark());
+	Config.Mem.lowWaterMark);
     storeAppendPrintf(sentry,
 	"{Swap-Max %d \"# Maximum disk cache (MB)\"}\n",
-	getCacheSwapMax() / (1 << 10));
+	Config.Swap.maxSize / (1 << 10));
     storeAppendPrintf(sentry,
 	"{Swap-High %d \"# High Water mark disk cache (%%)\"}\n",
-	getCacheSwapHighWaterMark());
+	Config.Swap.highWaterMark);
     storeAppendPrintf(sentry,
 	"{Swap-Low %d \"# Low water mark disk cache (%%)\"}\n",
-	getCacheSwapLowWaterMark());
+	Config.Swap.lowWaterMark);
     storeAppendPrintf(sentry,
 	"{HTTP-Max %d\"# Maximum size HTTP objects (KB)\"}\n",
-	getHttpMax() / (1 << 10));
+	Config.Http.maxObjSize / (1 << 10));
     storeAppendPrintf(sentry,
 	"{HTTP-TTL %d \"# Http object default TTL (hrs)\"}\n",
-	getHttpTTL() / 3600);
+	Config.Http.defaultTtl / 3600);
     storeAppendPrintf(sentry,
 	"{Gopher-Max %d \"# Maximum size gopher objects (KB)\"}\n",
-	getGopherMax() / (1 << 10));
+	Config.Gopher.maxObjSize / (1 << 10));
     storeAppendPrintf(sentry,
 	"{Gopher-TTL %d \"# TTL for gopher objects (hrs)\"}\n",
-	getGopherTTL() / 3600);
+	Config.Gopher.defaultTtl / 3600);
     storeAppendPrintf(sentry,
 	"{FTP-Max %d \"# Maximum size FTP objects (KB)\"}\n",
-	getFtpMax() / (1 << 10));
+	Config.Ftp.maxObjSize / (1 << 10));
     storeAppendPrintf(sentry,
 	"{FTP-TTL %d \"# TTL for FTP objects (hrs)\"}\n",
-	getFtpTTL() / 3600);
+	Config.Ftp.defaultTtl / 3600);
     storeAppendPrintf(sentry,
 	"{Neg-TTL %d \"# TTL for negative cache (s)\"}\n",
-	getNegativeTTL());
+	Config.negativeTtl);
     storeAppendPrintf(sentry,
 	"{ReadTimeout %d \"# Maximum idle connection (s)\"}\n",
-	getReadTimeout());
+	Config.readTimeout);
     storeAppendPrintf(sentry,
 	"{ClientLifetime %d \"# Lifetime for incoming HTTP requests\"}\n",
-	getClientLifetime());
+	Config.lifetimeDefault);
     storeAppendPrintf(sentry,
 	"{CleanRate %d \"# Rate for periodic object expiring\"}\n",
-	getCleanRate());
+	Config.cleanRate);
     /* Cachemgr.cgi expects an integer in the second field of the string */
     storeAppendPrintf(sentry,
 	"{HttpAccelMode %d \"# Is operating as an HTTP accelerator\"}\n",
