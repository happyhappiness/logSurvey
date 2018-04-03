 {
     int k;
     dnsserver_t *dns = NULL;
-    storeAppendPrintf(sentry, "{DNSServer Statistics:\n");
-    storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
+    storeAppendPrintf(sentry, "DNSServer Statistics:\n");
+    storeAppendPrintf(sentry, "dnsserver requests: %d\n",
 	DnsStats.requests);
-    storeAppendPrintf(sentry, "{dnsserver replies: %d}\n",
+    storeAppendPrintf(sentry, "dnsserver replies: %d\n",
 	DnsStats.replies);
-    storeAppendPrintf(sentry, "{number of dnsservers: %d}\n",
+    storeAppendPrintf(sentry, "number of dnsservers: %d\n",
 	NDnsServersAlloc);
-    storeAppendPrintf(sentry, "{dnsservers use histogram:}\n");
+    storeAppendPrintf(sentry, "dnsservers use histogram:\n");
     for (k = 0; k < NDnsServersAlloc; k++) {
-	storeAppendPrintf(sentry, "{    dnsserver #%d: %d}\n",
+	storeAppendPrintf(sentry, "    dnsserver #%d: %d\n",
 	    k + 1,
 	    DnsStats.hist[k]);
     }
-    storeAppendPrintf(sentry, "{}\n");
-    storeAppendPrintf(sentry, "{dnsservers status:}\n");
+    storeAppendPrintf(sentry, "\n");
+    storeAppendPrintf(sentry, "dnsservers status:\n");
     for (k = 0; k < NDnsServersAlloc; k++) {
 	dns = *(dns_child_table + k);
-	storeAppendPrintf(sentry, "{dnsserver #%d:}\n", k + 1);
-	storeAppendPrintf(sentry, "{    Flags: %c%c%c%c}\n",
+	storeAppendPrintf(sentry, "dnsserver #%d:\n", k + 1);
+	storeAppendPrintf(sentry, "    Flags: %c%c%c%c\n",
 	    EBIT_TEST(dns->flags, HELPER_ALIVE) ? 'A' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_BUSY) ? 'B' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_CLOSING) ? 'C' : ' ',
 	    EBIT_TEST(dns->flags, HELPER_SHUTDOWN) ? 'S' : ' ');
-	storeAppendPrintf(sentry, "{    FDs (in/out): %d/%d}\n",
+	storeAppendPrintf(sentry, "    FDs (in/out): %d/%d\n",
 	    dns->inpipe, dns->outpipe);
-	storeAppendPrintf(sentry, "{    Alive since: %s}\n",
+	storeAppendPrintf(sentry, "    Alive since: %s\n",
 	    mkrfc1123(dns->answer));
-	storeAppendPrintf(sentry, "{    Last Dispatched: %0.3f seconds ago}\n",
+	storeAppendPrintf(sentry, "    Last Dispatched: %0.3f seconds ago\n",
 	    0.001 * tvSubMsec(dns->dispatch_time, current_time));
-	storeAppendPrintf(sentry, "{    Read Buffer Size: %d bytes}\n",
+	storeAppendPrintf(sentry, "    Read Buffer Size: %d bytes\n",
 	    dns->size);
-	storeAppendPrintf(sentry, "{    Read Offset: %d bytes}\n",
+	storeAppendPrintf(sentry, "    Read Offset: %d bytes\n",
 	    dns->offset);
     }
-    storeAppendPrintf(sentry, "\n{Flags key:}\n\n");
-    storeAppendPrintf(sentry, "{   A = ALIVE}\n");
-    storeAppendPrintf(sentry, "{   B = BUSY}\n");
-    storeAppendPrintf(sentry, "{   C = CLOSING}\n");
-
-    storeAppendPrintf(sentry, close_bracket);
+    storeAppendPrintf(sentry, "\nFlags key:\n\n");
+    storeAppendPrintf(sentry, "   A = ALIVE\n");
+    storeAppendPrintf(sentry, "   B = BUSY\n");
+    storeAppendPrintf(sentry, "   C = CLOSING\n");
 }
 
 void
