		return BRANCH_COLOR_LOCAL;
	if (!strcasecmp(var+ofs, "current"))
		return BRANCH_COLOR_CURRENT;
	die("bad config variable '%s'", var);
}

static int git_branch_config(const char *var, const char *value, void *cb)
