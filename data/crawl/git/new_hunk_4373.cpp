	free(path);
}

int set_git_dir_init(const char *git_dir, const char *real_git_dir,
		     int exist_ok)
{
	if (real_git_dir) {
		struct stat st;

		if (!exist_ok && !stat(git_dir, &st))
			die("%s already exists", git_dir);

		if (!exist_ok && !stat(real_git_dir, &st))
			die("%s already exists", real_git_dir);

		/*
		 * make sure symlinks are resolved because we'll be
		 * moving the target repo later on in separate_git_dir()
		 */
		git_link = xstrdup(real_path(git_dir));
	}
	else {
		real_git_dir = real_path(git_dir);
		git_link = NULL;
	}
	set_git_dir(real_path(real_git_dir));
	return 0;
}

static void separate_git_dir(const char *git_dir)
{
	struct stat st;
	FILE *fp;

	if (!stat(git_link, &st)) {
		const char *src;

		if (S_ISREG(st.st_mode))
			src = read_gitfile_gently(git_link);
		else if (S_ISDIR(st.st_mode))
			src = git_link;
		else
			die("unable to handle file type %d", st.st_mode);

		if (rename(src, git_dir))
			die_errno("unable to move %s to %s", src, git_dir);
	}

	fp = fopen(git_link, "w");
	if (!fp)
		die("Could not create git link %s", git_link);
	fprintf(fp, "gitdir: %s\n", git_dir);
	fclose(fp);
}

int init_db(const char *template_dir, unsigned int flags)
{
	int reinit;
	const char *git_dir = get_git_dir();

	if (git_link)
		separate_git_dir(git_dir);

	safe_create_dir(git_dir, 0);

	init_is_bare_repository = is_bare_repository();

