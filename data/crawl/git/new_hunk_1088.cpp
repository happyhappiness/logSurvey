	const char *path;
	unsigned int mode, len;

	if (size < 23 || buf[size - 21])
		die(_("too-short tree object"));

	path = get_mode(buf, &mode);
	if (!path)
		die(_("malformed mode in tree entry for tree"));
	if (!*path)
		die(_("empty filename in tree entry for tree"));
	len = strlen(path) + 1;

	/* Initialize the descriptor entry */
