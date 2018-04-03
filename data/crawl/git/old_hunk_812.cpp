		OPT_END()
	};

	/*
	 * NEEDSWORK: Once the builtin difftool has been tested enough
	 * and git-legacy-difftool.perl is retired to contrib/, this preamble
	 * can be removed.
	 */
	if (!use_builtin_difftool()) {
		const char *path = mkpath("%s/git-legacy-difftool",
					  git_exec_path());

		if (sane_execvp(path, (char **)argv) < 0)
			die_errno("could not exec %s", path);

		return 0;
	}
	prefix = setup_git_directory();
	trace_repo_setup(prefix);
	setup_work_tree();
	/* NEEDSWORK: once we no longer spawn anything, remove this */
	setenv(GIT_DIR_ENVIRONMENT, absolute_path(get_git_dir()), 1);
	setenv(GIT_WORK_TREE_ENVIRONMENT, absolute_path(get_git_work_tree()), 1);
