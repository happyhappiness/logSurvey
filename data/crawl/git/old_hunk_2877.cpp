	if (!merge_names)
		merge_names = &fetch_head_file;

	filename = git_path("FETCH_HEAD");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die_errno(_("could not open '%s' for reading"), filename);
