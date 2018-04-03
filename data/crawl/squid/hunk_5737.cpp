 	client = inet_ntoa(al->cache.caddr);
     user1 = accessLogFormatName(al->cache.authuser);
     user2 = accessLogFormatName(al->cache.rfc931);
-    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %d %s:%s",
+    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %ld %s:%s",
 	client,
 	user2 ? user2 : dash_str,
 	user1 ? user1 : dash_str,
