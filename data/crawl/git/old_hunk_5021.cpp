	else if (!strcmp(k, "pull.octopus"))
		return git_config_string(&pull_octopus, k, v);
	else if (!strcmp(k, "merge.log") || !strcmp(k, "merge.summary")) {
		shortlog_len = git_config_bool(k, v) ? DEFAULT_MERGE_LOG_LEN : 0;
		return 0;
	}
	return git_diff_ui_config(k, v, cb);