 	DnsStats.replies);
     storeAppendPrintf(sentry, "number of dnsservers: %d\n",
 	NDnsServersAlloc);
-    storeAppendPrintf(sentry, "dnsservers use histogram:\n");
-    for (k = 0; k < NDnsServersAlloc; k++) {
-	storeAppendPrintf(sentry, "    dnsserver #%d: %d\n",
-	    k + 1,
-	    DnsStats.hist[k]);
-    }
     storeAppendPrintf(sentry, "\n");
-    storeAppendPrintf(sentry, "dnsservers status:\n");
+    storeAppendPrintf(sentry, "%7s\t%7s\t%11s\t%s\t%7s\t%7s\n",
+	"#",
+	"FD",
+	"# Requests",
+	"Flags",
+	"Time",
+	"Offset");
     for (k = 0; k < NDnsServersAlloc; k++) {
 	dns = *(dns_child_table + k);
-	storeAppendPrintf(sentry, "dnsserver #%d:\n", k + 1);
-	storeAppendPrintf(sentry, "    Flags: %c%c%c%c\n",
+	storeAppendPrintf(sentry, "%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\n",
+	    k + 1,
+	    dns->inpipe,
+	    DnsStats.hist[k],
 	    EBIT_TEST(dns->flags, HELPER_ALIVE) ? 'A' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_BUSY) ? 'B' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_CLOSING) ? 'C' : ' ',
-	    EBIT_TEST(dns->flags, HELPER_SHUTDOWN) ? 'S' : ' ');
-	storeAppendPrintf(sentry, "    FDs (in/out): %d/%d\n",
-	    dns->inpipe, dns->outpipe);
-	storeAppendPrintf(sentry, "    Alive since: %s\n",
-	    mkrfc1123(dns->answer));
-	storeAppendPrintf(sentry, "    Last Dispatched: %0.3f seconds ago\n",
-	    0.001 * tvSubMsec(dns->dispatch_time, current_time));
-	storeAppendPrintf(sentry, "    Read Buffer Size: %d bytes\n",
-	    dns->size);
-	storeAppendPrintf(sentry, "    Read Offset: %d bytes\n",
+	    EBIT_TEST(dns->flags, HELPER_SHUTDOWN) ? 'S' : ' ',
+	    0.001 * tvSubMsec(dns->dispatch_time, current_time),
 	    (int) dns->offset);
     }
     storeAppendPrintf(sentry, "\nFlags key:\n\n");