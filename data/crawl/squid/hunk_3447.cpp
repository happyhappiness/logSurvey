         safe_free(user);
 
     if (!Config.onoff.log_mime_hdrs) {
-        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %"PRId64" %s %s %s %s%s/%s %s\n",
+        logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %"PRId64" %s %s %s %s%s/%s %s\n",
                       (long int) current_time.tv_sec,
                       (int) current_time.tv_usec / 1000,
                       al->cache.msec,
                       client,
                       log_tags[al->cache.code],
+                      al->http.statusSfx(),
                       al->http.code,
                       al->cache.replySize,
                       al->_private.method_str,
