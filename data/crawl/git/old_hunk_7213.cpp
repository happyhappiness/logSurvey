	return reinit;
}

static void guess_repository_type(const char *git_dir)
{
	char cwd[PATH_MAX];
	const char *slash;

	if (0 <= is_bare_repository_cfg)
		return;
	if (!git_dir)
		return;

	/*
	 * "GIT_DIR=. git init" is always bare.
	 * "GIT_DIR=`pwd` git init" too.
	 */
	if (!strcmp(".", git_dir))
		goto force_bare;
	if (!getcwd(cwd, sizeof(cwd)))
		die("cannot tell cwd");
	if (!strcmp(git_dir, cwd))
		goto force_bare;
	/*
	 * "GIT_DIR=.git or GIT_DIR=something/.git is usually not.
	 */
	if (!strcmp(git_dir, ".git"))
		return;
	slash = strrchr(git_dir, '/');
	if (slash && !strcmp(slash, "/.git"))
		return;

	/*
	 * Otherwise it is often bare.  At this point
	 * we are just guessing.
	 */
 force_bare:
	is_bare_repository_cfg = 1;
	return;
}

static const char init_db_usage[] =
