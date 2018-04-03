	if (!(flags & INIT_DB_QUIET)) {
		const char *git_dir = get_git_dir();
		int len = strlen(git_dir);
		printf("%s%s Git repository in %s%s\n",
		       reinit ? "Reinitialized existing" : "Initialized empty",
		       shared_repository ? " shared" : "",
		       git_dir, len && git_dir[len-1] != '/' ? "/" : "");
	}

