 	return seen;
 }
 
+/*
+ * Checks the index to see whether any path in pathspec refers to
+ * something inside a submodule.  If so, dies with an error message.
+ */
 static void treat_gitlinks(const char **pathspec)
 {
 	int i;
 
 	if (!pathspec || !*pathspec)
 		return;
 
-	for (i = 0; i < active_nr; i++) {
-		struct cache_entry *ce = active_cache[i];
-		if (S_ISGITLINK(ce->ce_mode)) {
-			int len = ce_namelen(ce), j;
-			for (j = 0; pathspec[j]; j++) {
-				int len2 = strlen(pathspec[j]);
-				if (len2 <= len || pathspec[j][len] != '/' ||
-				    memcmp(ce->name, pathspec[j], len))
-					continue;
-				if (len2 == len + 1)
-					/* strip trailing slash */
-					pathspec[j] = xstrndup(ce->name, len);
-				else
-					die (_("Path '%s' is in submodule '%.*s'"),
-						pathspec[j], len, ce->name);
-			}
-		}
-	}
+	for (i = 0; pathspec[i]; i++)
+		pathspec[i] = check_path_for_gitlink(pathspec[i]);
 }
 
 static void refresh(int verbose, const char **pathspec)
