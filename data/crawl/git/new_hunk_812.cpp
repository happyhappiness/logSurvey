		OPT_END()
	};

	/* NEEDSWORK: once we no longer spawn anything, remove this */
	setenv(GIT_DIR_ENVIRONMENT, absolute_path(get_git_dir()), 1);
	setenv(GIT_WORK_TREE_ENVIRONMENT, absolute_path(get_git_work_tree()), 1);
