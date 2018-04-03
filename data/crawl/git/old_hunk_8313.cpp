
int is_inside_git_dir(void)
{
	if (inside_git_dir < 0) {
		char buffer[1024];

		if (is_bare_repository())
			return (inside_git_dir = 1);
		if (getcwd(buffer, sizeof(buffer))) {
			const char *git_dir = get_git_dir(), *cwd = buffer;
			while (*git_dir && *git_dir == *cwd) {
				git_dir++;
				cwd++;
			}
			inside_git_dir = !*git_dir;
		} else
			inside_git_dir = 0;
	}
	return inside_git_dir;
}

const char *setup_git_directory_gently(int *nongit_ok)
{
	static char cwd[PATH_MAX+1];
	const char *gitdirenv;
	int len, offset;

	/*
	 * If GIT_DIR is set explicitly, we're not going
	 * to do any discovery, but we still do repository
	 * validation.
	 */
	gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
	if (gitdirenv) {
		if (PATH_MAX - 40 < strlen(gitdirenv))
			die("'$%s' too big", GIT_DIR_ENVIRONMENT);
		if (is_git_directory(gitdirenv))
			return NULL;
		if (nongit_ok) {
			*nongit_ok = 1;
			return NULL;
