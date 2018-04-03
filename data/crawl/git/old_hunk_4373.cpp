	free(path);
}

int init_db(const char *template_dir, unsigned int flags)
{
	int reinit;

	safe_create_dir(get_git_dir(), 0);

	init_is_bare_repository = is_bare_repository();

