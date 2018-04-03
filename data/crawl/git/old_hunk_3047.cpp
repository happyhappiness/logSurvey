	int counter = 0, len, ret;
	struct strbuf symref = STRBUF_INIT;
	struct commit *commit = NULL;
	unsigned char rev[20];

	if (file_exists(path) && !is_empty_dir(path))
		die(_("'%s' already exists"), path);
