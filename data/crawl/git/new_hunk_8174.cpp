 */
const char *set_work_tree(const char *dir)
{
	char dir_buffer[PATH_MAX], *rel = NULL;
	static char buffer[PATH_MAX + 1];
	int len, suffix_len = strlen(DEFAULT_GIT_DIR_ENVIRONMENT) + 1;

	/* strip the variable 'dir' of the postfix "/.git" if it has it */
	len = strlen(dir);
	if (len > suffix_len &&
	    !strcmp(dir + len - suffix_len, "/" DEFAULT_GIT_DIR_ENVIRONMENT)) {
		if ((len - suffix_len) >= sizeof(dir_buffer))
			die("directory name too long");
		memcpy(dir_buffer, dir, len - suffix_len);
		dir_buffer[len - suffix_len] = '\0';

		/* are we inside the default work tree? */
		rel = get_relative_cwd(buffer, sizeof(buffer), dir_buffer);
	}

	/* if rel is set, the cwd is _not_ the current working tree */
	if (rel && *rel) {
		if (!is_absolute_path(dir))
			set_git_dir(make_absolute_path(dir));
		dir = dir_buffer;
		if (chdir(dir))
			die("cannot chdir to %s: %s", dir, strerror(errno));
		else
			strcat(rel, "/");
		inside_git_dir = 0;
	} else {
		rel = NULL;