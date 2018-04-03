	git_dir = getenv(GIT_DIR_ENVIRONMENT);
	work_tree = getenv(GIT_WORK_TREE_ENVIRONMENT);
	if ((!git_dir || is_bare_repository_cfg == 1) && work_tree)
		die("%s (or --work-tree=<directory>) not allowed without "
		    "specifying %s (or --git-dir=<directory>)",
		    GIT_WORK_TREE_ENVIRONMENT,
		    GIT_DIR_ENVIRONMENT);

