	}

	if (!(flags & INIT_DB_QUIET)) {
		int len = strlen(git_dir);
		printf("%s%s Git repository in %s%s\n",
		       reinit ? "Reinitialized existing" : "Initialized empty",
