 	client = inet_ntoa(al->cache.caddr);
     user = accessLogFormatName(al->cache.authuser ?
 	al->cache.authuser : al->cache.rfc931);
-    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %d %s %s %s %s%s/%s %s",
+    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
 	(int) current_time.tv_sec,
 	(int) current_time.tv_usec / 1000,
 	al->cache.msec,
 	client,
 	log_tags[al->cache.code],
 	al->http.code,
-	al->cache.size,
+	(long int) al->cache.size,
 	al->private.method_str,
 	al->url,
 	user ? user : dash_str,
