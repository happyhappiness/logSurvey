
int check_repository_format(void)
{
	return check_repository_format_gently(NULL);
}

const char *setup_git_directory(void)
{
	const char *retval = setup_git_directory_gently(NULL);
	check_repository_format();

	/* If the work tree is not the default one, recompute prefix */
	if (inside_work_tree < 0) {
