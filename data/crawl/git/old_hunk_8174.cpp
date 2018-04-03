 */
const char *set_work_tree(const char *dir)
{
	char dir_buffer[PATH_MAX];
	static char buffer[PATH_MAX + 1], *rel = NULL;
	int len, postfix_len = strlen(DEFAULT_GIT_DIR_ENVIRONMENT) + 1;

	/* strip the variable 'dir' of the postfix "/.git" if it has it */
	len = strlen(dir);
	if (len > postfix_len && !strcmp(dir + len - postfix_len,
				"/" DEFAULT_GIT_DIR_ENVIRONMENT)) {
			strncpy(dir_buffer, dir, len - postfix_len);

		/* are we inside the default work tree? */
		rel = get_relative_cwd(buffer, sizeof(buffer), dir_buffer);
	}
	/* if rel is set, the cwd is _not_ the current working tree */
	if (rel && *rel) {
		if (!is_absolute_path(dir))
			set_git_dir(make_absolute_path(dir));
		dir = dir_buffer;
		chdir(dir);
		strcat(rel, "/");
		inside_git_dir = 0;
	} else {
		rel = NULL;