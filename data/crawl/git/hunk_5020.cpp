 
 static int fmt_merge_msg_config(const char *key, const char *value, void *cb)
 {
-	static int found_merge_log = 0;
-	if (!strcmp("merge.log", key)) {
-		found_merge_log = 1;
-		shortlog_len = git_config_bool(key, value) ? DEFAULT_MERGE_LOG_LEN : 0;
-		return 0;
-	}
-	if (!found_merge_log && !strcmp("merge.summary", key)) {
-		shortlog_len = git_config_bool(key, value) ? DEFAULT_MERGE_LOG_LEN : 0;
-		return 0;
+	if (!strcmp(key, "merge.log") || !strcmp(key, "merge.summary")) {
+		int is_bool;
+		shortlog_len = git_config_bool_or_int(key, value, &is_bool);
+		if (!is_bool && shortlog_len < 0)
+			return error("%s: negative length %s", key, value);
+		if (is_bool && shortlog_len)
+			shortlog_len = DEFAULT_MERGE_LOG_LEN;
 	}
 	return 0;
 }
