	char *name;

	if (!dir)
		die_errno("cannot opendir '%s'", path);
	strcpy(pathbuf, path);
	name = pathbuf + strlen(path);
	*name++ = '/';
