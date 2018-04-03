 */
void set_git_work_tree(const char *new_work_tree)
{
	if (is_bare_repository_cfg >= 0)
		die("cannot set work tree after initialization");
	git_work_tree_initialized = 1;
	free(work_tree);
	work_tree = xstrdup(make_absolute_path(new_work_tree));
