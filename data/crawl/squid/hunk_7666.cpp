     }
 
     /* Sanity checks */
-    if (getClientLifetime() < getReadTimeout()) {
+    if (Config.lifetimeDefault < Config.readTimeout) {
 	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
-	    getClientLifetime(), getReadTimeout());
+	    Config.lifetimeDefault, Config.readTimeout);
 	printf("         This may cause serious problems with your cache!!!\n");
 	printf("         Change your configuration file.\n");
 	fflush(stdout);		/* print message */
     }
-    if (getCacheSwapMax() < (getCacheMemMax() >> 10)) {
-	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", getCacheSwapMax(), getCacheMemMax());
+    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
+	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
 	printf("         This will cause serious problems with your cache!!!\n");
 	printf("         Change your configuration file.\n");
-	Config.Swap.maxSize = getCacheMemMax() >> 10;
-	printf("         For this run, however, %s will use %d kbytes for cache_swap.\n", appname, getCacheSwapMax());
+	Config.Swap.maxSize = Config.Mem.maxSize >> 10;
+	printf("         For this run, however, %s will use %d kbytes for cache_swap.\n", appname, Config.Swap.maxSize);
 	fflush(stdout);		/* print message */
     }
-    if (getCleanRate() > -1 && getCleanRate() < 60) {
+    if (Config.cleanRate > -1 && Config.cleanRate < 60) {
 	Config.cleanRate = (30 * 60);
 	printf("WARNING: clean_rate is less than one minute.\n");
 	printf("         This will cause serious problems with your cache!!!\n");
 	printf("         Change your configuration file.\n");
-	printf("         For this run, however, %s will use %d minutes for clean_rate.\n", appname, (int) (getCleanRate() / 60));
+	printf("         For this run, however, %s will use %d minutes for clean_rate.\n", appname, (int) (Config.cleanRate / 60));
 	fflush(stdout);		/* print message */
     }
-    if (getDnsChildren() < 1) {
+    if (Config.dnsChildren < 1) {
 	printf("WARNING: dns_children was set to a bad value: %d\n",
-	    getDnsChildren());
+	    Config.dnsChildren);
 	Config.dnsChildren = DefaultDnsChildren;
 	printf("Setting it to the default (%d).\n", DefaultDnsChildren);
-    } else if (getDnsChildren() > DefaultDnsChildrenMax) {
+    } else if (Config.dnsChildren > DefaultDnsChildrenMax) {
 	printf("WARNING: dns_children was set to a bad value: %d\n",
-	    getDnsChildren());
+	    Config.dnsChildren);
 	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
 	Config.dnsChildren = DefaultDnsChildrenMax;
     }
-    if (getRedirectChildren() < 1) {
+    if (Config.redirectChildren < 1) {
 	printf("WARNING: redirect_children was set to a bad value: %d\n",
-	    getRedirectChildren());
+	    Config.redirectChildren);
 	Config.redirectChildren = DefaultRedirectChildren;
 	printf("Setting it to the default (%d).\n", DefaultRedirectChildren);
-    } else if (getRedirectChildren() > DefaultRedirectChildrenMax) {
+    } else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
 	printf("WARNING: redirect_children was set to a bad value: %d\n",
-	    getRedirectChildren());
+	    Config.redirectChildren);
 	printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
 	Config.redirectChildren = DefaultRedirectChildrenMax;
     }
