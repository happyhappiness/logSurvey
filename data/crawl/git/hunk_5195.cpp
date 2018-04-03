 
 static void show_ce_entry(const char *tag, struct cache_entry *ce)
 {
-	int len = prefix_len;
-	int offset = prefix_offset;
+	int len = max_prefix_len;
 
 	if (len >= ce_namelen(ce))
 		die("git ls-files: internal error - cache entry not superset of prefix");
