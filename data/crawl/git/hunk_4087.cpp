 			st.st_mtime = 0;
 	}
 
-	if (heads && nr_heads) {
-		qsort(heads, nr_heads, sizeof(*heads), compare_heads);
-		nr_heads = remove_duplicates(nr_heads, heads);
+	if (sought->nr) {
+		sort_string_list(sought);
+		remove_duplicates(sought);
 	}
 
 	if (!ref) {
 		packet_flush(fd[1]);
 		die("no matching remote head");
 	}
-	ref_cpy = do_fetch_pack(fd, ref, nr_heads, heads, pack_lockfile);
+	ref_cpy = do_fetch_pack(fd, ref, sought, pack_lockfile);
 
 	if (args.depth > 0) {
 		struct cache_time mtime;
