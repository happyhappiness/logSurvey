     if (user && !*user)
         safe_free(user);
 
-    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
-                  (int) current_time.tv_sec,
-                  (int) current_time.tv_usec / 1000,
-                  al->cache.msec,
-                  client,
-                  log_tags[al->cache.code],
-                  al->http.code,
-                  (long int) al->cache.size,
-                  al->_private.method_str,
-                  al->url,
-                  user ? user : dash_str,
-                  al->hier.ping.timedout ? "TIMEOUT_" : "",
-                  hier_strings[al->hier.code],
-                  al->hier.host,
-                  al->http.content_type);
-
-    safe_free(user);
-
-    if (Config.onoff.log_mime_hdrs) {
+    if (!Config.onoff.log_mime_hdrs) {
+        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
+                      (long int) current_time.tv_sec,
+                      (int) current_time.tv_usec / 1000,
+                      al->cache.msec,
+                      client,
+                      log_tags[al->cache.code],
+                      al->http.code,
+                      (long int) al->cache.size,
+                      al->_private.method_str,
+                      al->url,
+                      user ? user : dash_str,
+                      al->hier.ping.timedout ? "TIMEOUT_" : "",
+                      hier_strings[al->hier.code],
+                      al->hier.host,
+                      al->http.content_type);
+    } else {
         char *ereq = log_quote(al->headers.request);
         char *erep = log_quote(al->headers.reply);
-        logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
+        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s [%s] [%s]",
+                      (long int) current_time.tv_sec,
+                      (int) current_time.tv_usec / 1000,
+                      al->cache.msec,
+                      client,
+                      log_tags[al->cache.code],
+                      al->http.code,
+                      (long int) al->cache.size,
+                      al->_private.method_str,
+                      al->url,
+                      user ? user : dash_str,
+                      al->hier.ping.timedout ? "TIMEOUT_" : "",
+                      hier_strings[al->hier.code],
+                      al->hier.host,
+                      al->http.content_type,
+                      ereq,
+                      erep);
         safe_free(ereq);
         safe_free(erep);
-    } else {
-        logfilePrintf(logfile, "\n");
     }
 
+    safe_free(user);
 }
 
 static void