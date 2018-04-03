	if (gitdirenv[0] != '/') {
		setenv(GIT_DIR_ENVIRONMENT, gitdir, 1);
		gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
		if (PATH_MAX - 40 < strlen(gitdirenv)) {
			if (nongit_ok) {
				*nongit_ok = 1;