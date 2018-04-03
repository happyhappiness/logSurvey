 */
void set_git_work_tree(const char *new_work_tree)
{
	git_work_tree_initialized = 1;
	free(work_tree);
	work_tree = xstrdup(make_absolute_path(new_work_tree));
	is_bare_repository_cfg = 0;
}

const char *get_git_work_tree(void)
{
	if (startup_info && !startup_info->setup_explicit) {
		if (is_bare_repository_cfg == 1)
			return NULL;
		if (work_tree)
			is_bare_repository_cfg = 0;
		return work_tree;
	}

	if (!git_work_tree_initialized) {
		work_tree = getenv(GIT_WORK_TREE_ENVIRONMENT);
		/* core.bare = true overrides implicit and config work tree */
		if (!work_tree && is_bare_repository_cfg < 1) {
			work_tree = git_work_tree_cfg;
			/* make_absolute_path also normalizes the path */
			if (work_tree && !is_absolute_path(work_tree))
				work_tree = xstrdup(make_absolute_path(git_path("%s", work_tree)));
		} else if (work_tree)
			work_tree = xstrdup(make_absolute_path(work_tree));
		git_work_tree_initialized = 1;
		if (work_tree)
			is_bare_repository_cfg = 0;
	}
	return work_tree;
}
