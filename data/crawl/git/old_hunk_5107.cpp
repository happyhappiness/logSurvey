			return setup_bare_git_dir(work_tree_env, offset,
							len, cwd, nongit_ok);
		while (--offset > ceil_offset && cwd[offset] != '/');
		if (offset <= ceil_offset) {
			if (nongit_ok) {
				if (chdir(cwd))
					die_errno("Cannot come back to cwd");
				*nongit_ok = 1;
				return NULL;
			}
			die("Not a git repository (or any of the parent directories): %s", DEFAULT_GIT_DIR_ENVIRONMENT);
		}
		if (one_filesystem) {
			if (stat("..", &buf)) {
				cwd[offset] = '\0';