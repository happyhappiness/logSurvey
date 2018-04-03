 	code = HIER_MAX;
 
     if (emulate_httpd_log) {
-	if (cached_curtime != last_time) {
-	    s = mkhttpdlogtime(&cached_curtime);
+	if (squid_curtime != last_time) {
+	    s = mkhttpdlogtime(&squid_curtime);
 	    strcpy(time_str, s);
-	    last_time = cached_curtime;
+	    last_time = squid_curtime;
 	}
 	if (cache_host) {
 	    fprintf(cache_hierarchy_log, "[%s] %s %s%s %s\n",
