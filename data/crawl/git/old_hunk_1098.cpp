	    const char *template_dir, unsigned int flags)
{
	int reinit;

	set_git_dir_init(git_dir, real_git_dir, flags & INIT_DB_EXIST_OK);

	git_dir = get_git_dir();

	if (git_link)