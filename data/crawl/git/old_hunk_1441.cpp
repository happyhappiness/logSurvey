	fprintf(stderr, _("The following submodule paths contain changes that can\n"
			"not be found on any remote:\n"));
	for (i = 0; i < needs_pushing->nr; i++)
		printf("  %s\n", needs_pushing->items[i].string);
	fprintf(stderr, _("\nPlease try\n\n"
			  "	git push --recurse-submodules=on-demand\n\n"
			  "or cd to the path and use\n\n"