 	struct cache_entry *ce;
 	unsigned mode;
 
-	if (get_sha1("HEAD", head_sha1))
-		die("No such ref: HEAD");
+	verify_working_tree_path(head_sha1, path);
 
 	time(&now);
 	commit = xcalloc(1, sizeof(*commit));
