{
	const char *prefix;
	struct name_decoration *decoration;

	if (opt->show_source && commit->util)
		printf("\t%s", (char *) commit->util);
