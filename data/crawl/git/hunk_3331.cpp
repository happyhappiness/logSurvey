 int checkout_entry(struct cache_entry *ce,
 		   const struct checkout *state, char *topath)
 {
-	static struct strbuf path_buf = STRBUF_INIT;
-	char *path;
+	static struct strbuf path = STRBUF_INIT;
 	struct stat st;
-	int len;
 
 	if (topath)
 		return write_entry(ce, topath, state, 1);
 
-	strbuf_reset(&path_buf);
-	strbuf_add(&path_buf, state->base_dir, state->base_dir_len);
-	strbuf_add(&path_buf, ce->name, ce_namelen(ce));
-	path = path_buf.buf;
-	len = path_buf.len;
+	strbuf_reset(&path);
+	strbuf_add(&path, state->base_dir, state->base_dir_len);
+	strbuf_add(&path, ce->name, ce_namelen(ce));
 
-	if (!check_path(path, len, &st, state->base_dir_len)) {
+	if (!check_path(path.buf, path.len, &st, state->base_dir_len)) {
 		unsigned changed = ce_match_stat(ce, &st, CE_MATCH_IGNORE_VALID|CE_MATCH_IGNORE_SKIP_WORKTREE);
 		if (!changed)
 			return 0;
 		if (!state->force) {
 			if (!state->quiet)
-				fprintf(stderr, "%s already exists, no checkout\n", path);
+				fprintf(stderr,
+					"%s already exists, no checkout\n",
+					path.buf);
 			return -1;
 		}
 
