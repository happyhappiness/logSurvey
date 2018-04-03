			return setup_bare_git_dir(work_tree_env, offset,
							len, cwd, nongit_ok);
		while (--offset > ceil_offset && cwd[offset] != '/');
		if (offset <= ceil_offset)
			return setup_nongit(cwd, nongit_ok);
		if (one_filesystem) {
			if (stat("..", &buf)) {
				cwd[offset] = '\0';