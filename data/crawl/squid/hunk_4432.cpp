     int j;
     net_db_peer *p;
     storeAppendPrintf(sentry, "Network DB Statistics:\n");
-    storeAppendPrintf(sentry, "%-16.16s %9s %7s %5s %s\n",
+    storeAppendPrintf(sentry, "%-46.46s %9s %7s %5s %s\n",  /* Max between 16 (IPv4) or 46 (IPv6)   */
                       "Network",
                       "recv/sent",
                       "RTT",
