	struct pretty_print_context ctx = {0};

	printf(_("Squash commit -- not updating HEAD\n"));
	filename = git_path("SQUASH_MSG");
	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
		die_errno(_("Could not write to '%s'"), filename);
