			die("Not a git repository");
		}
		setenv(GIT_DIR_ENVIRONMENT, cwd, 1);
	}

	if (PATH_MAX - 40 < strlen(gitdirenv)) {
