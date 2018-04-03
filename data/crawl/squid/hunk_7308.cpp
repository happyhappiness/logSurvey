 dnsStats(StoreEntry * sentry)
 {
     int k;
-
+    dnsserver_t *dns = NULL;
     storeAppendPrintf(sentry, "{DNSServer Statistics:\n");
     storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
 	DnsStats.requests);
