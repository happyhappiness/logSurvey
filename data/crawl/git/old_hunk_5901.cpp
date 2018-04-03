	char *name;

	if (!dir)
		die("cannot opendir %s (%s)", path, strerror(errno));
	strcpy(pathbuf, path);
	name = pathbuf + strlen(path);
	*name++ = '/';
