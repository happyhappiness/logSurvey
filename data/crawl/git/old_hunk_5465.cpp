		return DIFF_COMMIT;
	if (!strcasecmp(var+ofs, "whitespace"))
		return DIFF_WHITESPACE;
	die("bad config variable '%s'", var);
}

static int git_config_rename(const char *var, const char *value)
