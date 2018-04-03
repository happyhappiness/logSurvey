     return (NULL);
 }
 
-
-void hierarchy_log_append(entry, code, timeout, cache_host)
-     StoreEntry *entry;
+void hierarchyNote(request, code, timeout, cache_host)
+     request_t *request;
      hier_code code;
      int timeout;
      char *cache_host;
 {
-    char *url = entry->url;
-    MemObject *mem = entry->mem_obj;
-    static time_t last_time = 0;
-    LOCAL_ARRAY(char, time_str, 128);
-    char *s = NULL;
-
-    if (!cache_hierarchy_log)
-	return;
-
-    if (code > HIER_MAX)
-	code = HIER_MAX;
-    if (mem)
-	mem->request->hierarchy_code = code;
-    if (mem && cache_host)
-	mem->request->hierarchy_host = xstrdup(cache_host);
-
-    if (Config.commonLogFormat) {
-	if (squid_curtime != last_time) {
-	    s = mkhttpdlogtime(&squid_curtime);
-	    strcpy(time_str, s);
-	    last_time = squid_curtime;
-	}
-	if (cache_host) {
-	    fprintf(cache_hierarchy_log, "[%s] %s %s%s %s\n",
-		time_str,
-		url,
-		timeout ? "TIMEOUT_" : "",
-		hier_strings[code],
-		cache_host);
-	} else {
-	    fprintf(cache_hierarchy_log, "[%s] %s %s%s\n",
-		time_str,
-		url,
-		timeout ? "TIMEOUT_" : "",
-		hier_strings[code]);
-	}
-    } else {
-	if (cache_host) {
-	    fprintf(cache_hierarchy_log, "%d.%03d %s %s%s %s\n",
-		(int) current_time.tv_sec,
-		(int) current_time.tv_usec / 1000,
-		url,
-		timeout ? "TIMEOUT_" : "",
-		hier_strings[code],
-		cache_host);
-	} else {
-	    fprintf(cache_hierarchy_log, "%d.%03d %s %s%s\n",
-		(int) current_time.tv_sec,
-		(int) current_time.tv_usec / 1000,
-		url,
-		timeout ? "TIMEOUT_" : "",
-		hier_strings[code]);
-	}
+    if (request) {
+	request->hierarchy.code = code;
+	request->hierarchy.timeout = timeout;
+	request->hierarchy.host = xstrdup(cache_host);
     }
-    if (unbuffered_logs)
-	fflush(cache_hierarchy_log);
 }
 
 static int edgeWouldBePinged(e, request)
