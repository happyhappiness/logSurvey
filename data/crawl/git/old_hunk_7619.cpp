	fprintf(fp,
		"\n"
		"# Please enter the commit message for your changes.\n"
		"# (Comment lines starting with '#' will not be included)\n");
	if (only_include_assumed)
		fprintf(fp, "# %s\n", only_include_assumed);

