 		int is_bool;
 		shortlog_len = git_config_bool_or_int(k, v, &is_bool);
 		if (!is_bool && shortlog_len < 0)
-			return error("%s: negative length %s", k, v);
+			return error(_("%s: negative length %s"), k, v);
 		if (is_bool && shortlog_len)
 			shortlog_len = DEFAULT_MERGE_LOG_LEN;
 		return 0;
