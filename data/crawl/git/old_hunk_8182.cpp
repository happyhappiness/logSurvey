{
	const char *retval = setup_git_directory_gently(NULL);
	check_repository_format();
	return retval;
}
