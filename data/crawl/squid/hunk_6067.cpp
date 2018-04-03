     if (al->hier.host[0] == '\0')
 	xstrncpy(al->hier.host, dash_str, SQUIDHOSTNAMELEN);
 
-    memBufDefInit(&mb);
-
     if (Config.onoff.common_log)
-	accessLogCommon(al, &mb);
+	accessLogCommon(al);
     else
-	accessLogSquid(al, &mb);
+	accessLogSquid(al);
     if (Config.onoff.log_mime_hdrs) {
 	char *ereq = log_quote(al->headers.request);
 	char *erep = log_quote(al->headers.reply);
-	memBufPrintf(&mb, " [%s] [%s]\n", ereq, erep);
+	logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
 	safe_free(ereq);
 	safe_free(erep);
     } else {
-	memBufPrintf(&mb, "\n");
+	logfilePrintf(logfile, "\n");
     }
-    file_write_mbuf(LogfileFD, -1, mb, NULL, NULL);
-    safe_free(xbuf);
+    logfileFlush(logfile);
 #if MULTICAST_MISS_STREAM
     if (al->cache.code != LOG_TCP_MISS)
 	(void) 0;
