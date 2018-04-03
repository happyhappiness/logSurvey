	return get_pathspec(prefix, result);
}

static const char *add_slash(const char *path)
{
	int len = strlen(path);
