	if (check_repository_format_gently(".", nongit_ok))
		return NULL;

	/* --work-tree is set without --git-dir; use discovered one */
	if (getenv(GIT_WORK_TREE_ENVIRONMENT) || git_work_tree_cfg) {
		const char *gitdir;

		gitdir = offset == len ? "." : xmemdupz(cwd, offset);
		if (chdir(cwd))
			die_errno("Could not come back to cwd");
		return setup_explicit_git_dir(gitdir, cwd, len, nongit_ok);
	}

	inside_git_dir = 1;
	inside_work_tree = 0;
	if (offset != len) {
