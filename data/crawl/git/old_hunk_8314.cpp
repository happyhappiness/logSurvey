
	if (!getcwd(cwd, sizeof(cwd)-1) || cwd[0] != '/')
		die("Unable to read current working directory");

	offset = len = strlen(cwd);
	for (;;) {
		if (is_git_directory(".git"))
			break;
		chdir("..");
		do {
			if (!offset) {
				if (is_git_directory(cwd)) {
					if (chdir(cwd))
						die("Cannot come back to cwd");
					setenv(GIT_DIR_ENVIRONMENT, cwd, 1);
					inside_git_dir = 1;
					return NULL;
				}
				if (nongit_ok) {
					if (chdir(cwd))
						die("Cannot come back to cwd");
					*nongit_ok = 1;
					return NULL;
				}
				die("Not a git repository");
			}
		} while (cwd[--offset] != '/');
	}

	if (offset == len)
		return NULL;

	/* Make "offset" point to past the '/', and add a '/' at the end */
	offset++;
	cwd[len++] = '/';
	cwd[len] = 0;
	inside_git_dir = !prefixcmp(cwd + offset, ".git/");
	return cwd + offset;
}

int git_config_perm(const char *var, const char *value)
