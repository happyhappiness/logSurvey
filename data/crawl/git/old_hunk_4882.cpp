	 * without --bare.  Catch the error early.
	 */
	git_dir = getenv(GIT_DIR_ENVIRONMENT);
	if ((!git_dir || is_bare_repository_cfg == 1)
	    && getenv(GIT_WORK_TREE_ENVIRONMENT))
		die("%s (or --work-tree=<directory>) not allowed without "
		    "specifying %s (or --git-dir=<directory>)",
		    GIT_WORK_TREE_ENVIRONMENT,
