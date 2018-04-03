
static int fmt_merge_msg_config(const char *key, const char *value, void *cb)
{
	if (!strcmp(key, "merge.log") || !strcmp(key, "merge.summary")) {
		int is_bool;
		shortlog_len = git_config_bool_or_int(key, value, &is_bool);
		if (!is_bool && shortlog_len < 0)
			return error("%s: negative length %s", key, value);
		if (is_bool && shortlog_len)
			shortlog_len = DEFAULT_MERGE_LOG_LEN;
	}
	return 0;
}
