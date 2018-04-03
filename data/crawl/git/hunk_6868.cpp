 	int cnt = 0;
 	struct rev_info rev;
 
+	discard_cache();
 	if (read_cache() < 0)
 		die("failed to read the cache");
 
