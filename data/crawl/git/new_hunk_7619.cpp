	fprintf(fp,
		"\n"
		"# Please enter the commit message for your changes.\n"
		"# (Comment lines starting with '#' will ");
	if (cleanup_mode == CLEANUP_ALL)
		fprintf(fp, "not be included)\n");
	else /* CLEANUP_SPACE, that is. */
		fprintf(fp, "be kept.\n"
			"# You can remove them yourself if you want to)\n");
	if (only_include_assumed)
		fprintf(fp, "# %s\n", only_include_assumed);

