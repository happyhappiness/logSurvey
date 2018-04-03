	closedir(dir);
}

static int create_default_files(const char *git_dir, const char *template_path)
{
	unsigned len = strlen(git_dir);
	static char path[PATH_MAX];
