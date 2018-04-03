     } else {
 	if (cache_host) {
 	    fprintf(cache_hierarchy_log, "%d %s %s%s %s\n",
-		(int) cached_curtime,
+		(int) squid_curtime,
 		url,
 		timeout ? "TIMEOUT_" : "",
 		hier_strings[code],
 		cache_host);
 	} else {
 	    fprintf(cache_hierarchy_log, "%d %s %s%s\n",
-		(int) cached_curtime,
+		(int) squid_curtime,
 		url,
 		timeout ? "TIMEOUT_" : "",
 		hier_strings[code]);
