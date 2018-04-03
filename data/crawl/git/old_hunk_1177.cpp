	 */
	if (get_shared_repository()) {
		adjust_shared_perm(get_git_dir());
		adjust_shared_perm(git_path_buf(&buf, "refs"));
		adjust_shared_perm(git_path_buf(&buf, "refs/heads"));
		adjust_shared_perm(git_path_buf(&buf, "refs/tags"));
	}

	/*
	 * Create the default symlink from ".git/HEAD" to the "master"
	 * branch, if it does not exist yet.
