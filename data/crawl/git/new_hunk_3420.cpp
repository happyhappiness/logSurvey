	return 0;
}

static int prune_object(const char *fullpath, const unsigned char *sha1)
{
	struct stat st;
	if (lstat(fullpath, &st))
		return error("Could not stat '%s'", fullpath);
