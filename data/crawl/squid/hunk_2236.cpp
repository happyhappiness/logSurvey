     char clientip[MAX_IPSTRLEN];
     al->getLogClientIp(clientip, MAX_IPSTRLEN);
 
-    logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %"PRId64" %s %s %s %s%s/%s %s%s",
+    logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %" PRId64 " %s %s %s %s%s/%s %s%s",
                   (long int) current_time.tv_sec,
                   (int) current_time.tv_usec / 1000,
                   al->cache.msec,
