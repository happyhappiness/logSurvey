{
	int i;

	fprintf(stderr, "The following submodule paths contain changes that can\n"
			"not be found on any remote:\n");
	for (i = 0; i < needs_pushing->nr; i++)
		printf("  %s\n", needs_pushing->items[i].string);
	fprintf(stderr, "\nPlease try\n\n"
			"	git push --recurse-submodules=on-demand\n\n"
			"or cd to the path and use\n\n"
			"	git push\n\n"
			"to push them to a remote.\n\n");

	string_list_clear(needs_pushing, 0);

	die("Aborting.");
}

static int run_pre_push_hook(struct transport *transport,