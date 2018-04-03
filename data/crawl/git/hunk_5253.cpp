 	       sizeof(*builtin_formats)*ARRAY_SIZE(builtin_formats));
 }
 
-static struct cmt_fmt_map *find_commit_format(const char *sought)
+static struct cmt_fmt_map *find_commit_format_recursive(const char *sought,
+							const char *original,
+							int num_redirections)
 {
 	struct cmt_fmt_map *found = NULL;
 	size_t found_match_len = 0;
 	int i;
 
-	if (!commit_formats)
-		setup_commit_formats();
+	if (num_redirections >= commit_formats_len)
+		die("invalid --pretty format: "
+		    "'%s' references an alias which points to itself",
+		    original);
 
 	for (i = 0; i < commit_formats_len; i++) {
 		size_t match_len;
