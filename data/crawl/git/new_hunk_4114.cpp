	return newpath;
}

static int dir_in_way(const char *path, int check_working_copy)
{
	int pos, pathlen = strlen(path);
