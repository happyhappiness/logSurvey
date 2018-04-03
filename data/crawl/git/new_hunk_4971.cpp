	return cleanup_path(pathname);
}

int validate_headref(const char *path)
{
	struct stat st;
