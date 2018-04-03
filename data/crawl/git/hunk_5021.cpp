 	else if (!strcmp(k, "pull.octopus"))
 		return git_config_string(&pull_octopus, k, v);
 	else if (!strcmp(k, "merge.log") || !strcmp(k, "merge.summary")) {
-		shortlog_len = git_config_bool(k, v) ? DEFAULT_MERGE_LOG_LEN : 0;
+		int is_bool;
+		shortlog_len = git_config_bool_or_int(k, v, &is_bool);
+		if (!is_bool && shortlog_len < 0)
+			return error("%s: negative length %s", k, v);
+		if (is_bool && shortlog_len)
+			shortlog_len = DEFAULT_MERGE_LOG_LEN;
 		return 0;
 	}
 	return git_diff_ui_config(k, v, cb);