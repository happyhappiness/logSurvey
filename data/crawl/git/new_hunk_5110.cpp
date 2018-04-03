	return path;
}

static const char *setup_explicit_git_dir(const char *gitdirenv,
				const char *work_tree_env, int *nongit_ok)
{
	static char buffer[1024 + 1];
	const char *retval;

	if (PATH_MAX - 40 < strlen(gitdirenv))
		die("'$%s' too big", GIT_DIR_ENVIRONMENT);
	if (!is_git_directory(gitdirenv)) {
		if (nongit_ok) {
			*nongit_ok = 1;
			return NULL;
		}
		die("Not a git repository: '%s'", gitdirenv);
	}
	if (!work_tree_env) {
		retval = set_work_tree(gitdirenv);
		/* config may override worktree */
		if (check_repository_format_gently(nongit_ok))
			return NULL;
		return retval;
	}
	if (check_repository_format_gently(nongit_ok))
		return NULL;
	retval = get_relative_cwd(buffer, sizeof(buffer) - 1,
			get_git_work_tree());
	if (!retval || !*retval)
		return NULL;
	set_git_dir(make_absolute_path(gitdirenv));
	if (chdir(work_tree_env) < 0)
		die_errno ("Could not chdir to '%s'", work_tree_env);
	strcat(buffer, "/");
	return retval;
}

/*
 * We cannot decide in this function whether we are in the work tree or
 * not, since the config can only be read _after_ this function was called.
