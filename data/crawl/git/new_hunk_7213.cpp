	return reinit;
}

int init_db(const char *template_dir, unsigned int flags)
{
	const char *sha1_dir;
	char *path;
	int len, reinit;

	safe_create_dir(get_git_dir(), 0);

	/* Check to see if the repository version is right.
	 * Note that a newly created repository does not have
	 * config file, so this will not fail.  What we are catching
	 * is an attempt to reinitialize new repository with an old tool.
	 */
	check_repository_format();

	reinit = create_default_files(template_dir);

	sha1_dir = get_object_directory();
	len = strlen(sha1_dir);
	path = xmalloc(len + 40);
	memcpy(path, sha1_dir, len);

	safe_create_dir(sha1_dir, 1);
	strcpy(path+len, "/pack");
	safe_create_dir(path, 1);
	strcpy(path+len, "/info");
	safe_create_dir(path, 1);

	if (shared_repository) {
		char buf[10];
		/* We do not spell "group" and such, so that
		 * the configuration can be read by older version
		 * of git. Note, we use octal numbers for new share modes,
		 * and compatibility values for PERM_GROUP and
		 * PERM_EVERYBODY.
		 */
		if (shared_repository == PERM_GROUP)
			sprintf(buf, "%d", OLD_PERM_GROUP);
		else if (shared_repository == PERM_EVERYBODY)
			sprintf(buf, "%d", OLD_PERM_EVERYBODY);
		else
			sprintf(buf, "0%o", shared_repository);
		git_config_set("core.sharedrepository", buf);
		git_config_set("receive.denyNonFastforwards", "true");
	}

	if (!(flags & INIT_DB_QUIET))
		printf("%s%s Git repository in %s/\n",
		       reinit ? "Reinitialized existing" : "Initialized empty",
		       shared_repository ? " shared" : "",
		       get_git_dir());

	return 0;
}

static int guess_repository_type(const char *git_dir)
{
	char cwd[PATH_MAX];
	const char *slash;

	/*
	 * "GIT_DIR=. git init" is always bare.
	 * "GIT_DIR=`pwd` git init" too.
	 */
	if (!strcmp(".", git_dir))
		return 1;
	if (!getcwd(cwd, sizeof(cwd)))
		die("cannot tell cwd");
	if (!strcmp(git_dir, cwd))
		return 1;
	/*
	 * "GIT_DIR=.git or GIT_DIR=something/.git is usually not.
	 */
	if (!strcmp(git_dir, ".git"))
		return 0;
	slash = strrchr(git_dir, '/');
	if (slash && !strcmp(slash, "/.git"))
		return 0;

	/*
	 * Otherwise it is often bare.  At this point
	 * we are just guessing.
	 */
	return 1;
}

static const char init_db_usage[] =
