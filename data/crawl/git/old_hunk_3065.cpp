	int counter = 0, len, ret;
	unsigned char rev[20];

	if (!new->commit)
		die(_("no branch specified"));
	if (file_exists(path) && !is_empty_dir(path))
		die(_("'%s' already exists"), path);

