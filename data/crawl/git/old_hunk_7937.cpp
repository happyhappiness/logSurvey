		if (PATH_MAX - 40 < strlen(gitdirenv))
			die("'$%s' too big", GIT_DIR_ENVIRONMENT);
		if (is_git_directory(gitdirenv)) {
			if (!work_tree_env)
				return set_work_tree(gitdirenv);
			return NULL;
		}
		if (nongit_ok) {
			*nongit_ok = 1;
