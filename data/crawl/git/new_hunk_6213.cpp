	die("bad config variable '%s'", var);
}

static int git_config_rename(const char *var, const char *value)
{
	if (!value)
		return DIFF_DETECT_RENAME;
	if (!strcasecmp(value, "copies") || !strcasecmp(value, "copy"))
		return  DIFF_DETECT_COPY;
	return git_config_bool(var,value) ? DIFF_DETECT_RENAME : 0;
}

/*
 * These are to give UI layer defaults.
 * The core-level commands such as git-diff-files should
