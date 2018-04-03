 	return 0;
 }
 
+int add_file_to_index(struct index_state *istate, const char *path, int verbose)
+{
+	struct stat st;
+	if (lstat(path, &st))
+		die("%s: unable to stat (%s)", path, strerror(errno));
+	return add_to_index(istate, path, &st, verbose);
+}
+
 struct cache_entry *make_cache_entry(unsigned int mode,
 		const unsigned char *sha1, const char *path, int stage,
 		int refresh)