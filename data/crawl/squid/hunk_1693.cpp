     storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
     storeAppendPrintf(sentry, "\nThe Queue:\n");
     storeAppendPrintf(sentry, "                       DELAY SINCE\n");
-    storeAppendPrintf(sentry, "  ID   SIZE SENDS FIRST SEND LAST SEND\n");
-    storeAppendPrintf(sentry, "------ ---- ----- ---------- ---------\n");
+    storeAppendPrintf(sentry, "  ID   SIZE SENDS FIRST SEND LAST SEND M FQDN\n");
+    storeAppendPrintf(sentry, "------ ---- ----- ---------- --------- - ----\n");
 
     for (n = lru_list.head; n; n = n->next) {
         q = (idns_query *)n->data;
-        storeAppendPrintf(sentry, "%#06x %4d %5d %10.3f %9.3f\n",
+        storeAppendPrintf(sentry, "%#06x %4d %5d %10.3f %9.3f %c %s\n",
                           (int) q->query_id, (int) q->sz, q->nsends,
                           tvSubDsec(q->start_t, current_time),
-                          tvSubDsec(q->sent_t, current_time));
+                          tvSubDsec(q->sent_t, current_time),
+                          (q->permit_mdns? 'M':' '),
+                          q->name);
     }
 
     if (Config.dns.packet_max > 0)
-        storeAppendPrintf(sentry, "DNS jumbo-grams: %zd Bytes\n", Config.dns.packet_max);
+        storeAppendPrintf(sentry, "\nDNS jumbo-grams: %zd Bytes\n", Config.dns.packet_max);
     else
-        storeAppendPrintf(sentry, "DNS jumbo-grams: not working\n");
+        storeAppendPrintf(sentry, "\nDNS jumbo-grams: not working\n");
 
     storeAppendPrintf(sentry, "\nNameservers:\n");
     storeAppendPrintf(sentry, "IP ADDRESS                                     # QUERIES # REPLIES Type\n");
