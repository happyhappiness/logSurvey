	return git_dir;
}

const char *get_git_work_tree(void)
{
	static int initialized = 0;
	if (!initialized) {
		work_tree = getenv(GIT_WORK_TREE_ENVIRONMENT);
		/* core.bare = true overrides implicit and config work tree */
		if (!work_tree && is_bare_repository_cfg < 1) {
