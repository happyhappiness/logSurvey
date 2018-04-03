		return DIFF_COMMIT;
	if (!strcasecmp(var+ofs, "whitespace"))
		return DIFF_WHITESPACE;
	return -1;
}

static int git_config_rename(const char *var, const char *value)
