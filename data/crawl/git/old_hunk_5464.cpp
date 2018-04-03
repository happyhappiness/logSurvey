		return WT_STATUS_NOBRANCH;
	if (!strcasecmp(var+offset, "unmerged"))
		return WT_STATUS_UNMERGED;
	die("bad config variable '%s'", var);
}

static int git_status_config(const char *k, const char *v, void *cb)
