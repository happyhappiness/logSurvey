 		cutoff_resolve = git_config_int(var, value);
 	else if (!strcmp(var, "gc.rerereunresolved"))
 		cutoff_noresolve = git_config_int(var, value);
+	else if (!strcmp(var, "rerere.enabled"))
+		rerere_enabled = git_config_bool(var, value);
 	else
 		return git_default_config(var, value);
 	return 0;
 }
 
-int cmd_rerere(int argc, const char **argv, const char *prefix)
+static int is_rerere_enabled(void)
 {
-	struct path_list merge_rr = { NULL, 0, 0, 1 };
-	int i, fd = -1;
 	struct stat st;
+	const char *rr_cache;
+	int rr_cache_exists;
 
-	if (stat(git_path("rr-cache"), &st) || !S_ISDIR(st.st_mode))
+	if (!rerere_enabled)
 		return 0;
 
+	rr_cache = git_path("rr-cache");
+	rr_cache_exists = !stat(rr_cache, &st) && S_ISDIR(st.st_mode);
+	if (rerere_enabled < 0)
+		return rr_cache_exists;
+
+	if (!rr_cache_exists &&
+	    (mkdir(rr_cache, 0777) || adjust_shared_perm(rr_cache)))
+		die("Could not create directory %s", rr_cache);
+	return 1;
+}
+
+int cmd_rerere(int argc, const char **argv, const char *prefix)
+{
+	struct path_list merge_rr = { NULL, 0, 0, 1 };
+	int i, fd = -1;
+
 	git_config(git_rerere_config);
+	if (!is_rerere_enabled())
+		return 0;
 
 	merge_rr_path = xstrdup(git_path("rr-cache/MERGE_RR"));
 	fd = hold_lock_file_for_update(&write_lock, merge_rr_path, 1);
