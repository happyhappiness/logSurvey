 	add_pathspec_matches_against_index(pathspec, seen, i);
 	return seen;
 }
+
+/*
+ * Check the index to see whether path refers to a submodule, or
+ * something inside a submodule.  If the former, returns the path with
+ * any trailing slash stripped.  If the latter, dies with an error
+ * message.
+ */
+const char *check_path_for_gitlink(const char *path)
+{
+	int i, path_len = strlen(path);
+	for (i = 0; i < active_nr; i++) {
+		struct cache_entry *ce = active_cache[i];
+		if (S_ISGITLINK(ce->ce_mode)) {
+			int ce_len = ce_namelen(ce);
+			if (path_len <= ce_len || path[ce_len] != '/' ||
+			    memcmp(ce->name, path, ce_len))
+				/* path does not refer to this
+				 * submodule or anything inside it */
+				continue;
+			if (path_len == ce_len + 1) {
+				/* path refers to submodule;
+				 * strip trailing slash */
+				return xstrndup(ce->name, ce_len);
+			} else {
+				die (_("Path '%s' is in submodule '%.*s'"),
+				     path, ce_len, ce->name);
+			}
+		}
+	}
+	return path;
+}
