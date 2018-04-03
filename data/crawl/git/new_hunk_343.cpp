		die("BUG: unhandled setup_git_directory_1() result");
	}

	if (prefix)
		setenv(GIT_PREFIX_ENVIRONMENT, prefix, 1);
	else