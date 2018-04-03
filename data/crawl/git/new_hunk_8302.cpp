	struct dirent *de;
	char pathbuf[PATH_MAX];
	char *name;

	if (!dir)
		die("cannot opendir %s (%s)", path, strerror(errno));
	strcpy(pathbuf, path);
