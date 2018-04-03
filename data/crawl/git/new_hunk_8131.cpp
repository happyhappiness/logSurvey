			usage(init_db_usage);
	}

	/*
	 * GIT_WORK_TREE makes sense only in conjunction with GIT_DIR
	 * without --bare.  Catch the error early.
	 */
	git_dir = getenv(GIT_DIR_ENVIRONMENT);
	if ((!git_dir || is_bare_repository_cfg == 1)
	    && getenv(GIT_WORK_TREE_ENVIRONMENT))
		die("%s (or --work-tree=<directory>) not allowed without "
		    "specifying %s (or --git-dir=<directory>)",
		    GIT_WORK_TREE_ENVIRONMENT,
		    GIT_DIR_ENVIRONMENT);

	guess_repository_type(git_dir);

	if (is_bare_repository_cfg <= 0) {
		git_work_tree_cfg = xcalloc(PATH_MAX, 1);
		if (!getcwd(git_work_tree_cfg, PATH_MAX))
			die ("Cannot access current working directory.");
		if (access(get_git_work_tree(), X_OK))
			die ("Cannot access work tree '%s'",
			     get_git_work_tree());
	}

	/*
	 * Set up the default .git directory contents
