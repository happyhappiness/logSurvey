	return mkstemps(path, suffix_len);
}

int validate_headref(const char *path)
{
	struct stat st;