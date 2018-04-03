	return 0;
}

static int git_commit_config(const char *k, const char *v, void *cb)
{
	struct wt_status *s = cb;
