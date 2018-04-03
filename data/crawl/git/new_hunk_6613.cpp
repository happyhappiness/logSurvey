	struct name_decoration *decoration;

	if (opt->show_source && commit->util)
		printf("\t%s", (char *) commit->util);
	if (!opt->show_decorations)
		return;
	decoration = lookup_decoration(&name_decoration, &commit->object);