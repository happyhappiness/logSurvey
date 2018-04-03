	return inside_work_tree;
}

/*
 * set_work_tree() is only ever called if you set GIT_DIR explicitly.
 * The old behaviour (which we retain here) is to set the work tree root
 * to the cwd, unless overridden by the config, the command line, or
 * GIT_WORK_TREE.
 */
static const char *set_work_tree(const char *dir)
{
	char buffer[PATH_MAX + 1];

	if (!getcwd(buffer, sizeof(buffer)))
		die ("Could not get the current working directory");
	git_work_tree_cfg = xstrdup(buffer);
	inside_work_tree = 1;

	return NULL;
}

void setup_work_tree(void)
{
	const char *work_tree, *git_dir;
