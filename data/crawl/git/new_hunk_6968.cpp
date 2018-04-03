		garbage_collect(&merge_rr);
	else if (!strcmp(argv[1], "status"))
		for (i = 0; i < merge_rr.nr; i++)
			printf("%s\n", merge_rr.items[i].string);
	else if (!strcmp(argv[1], "diff"))
		for (i = 0; i < merge_rr.nr; i++) {
			const char *path = merge_rr.items[i].string;
			const char *name = (const char *)merge_rr.items[i].util;
			diff_two(rr_path(name, "preimage"), path, path, path);
		}
	else
		usage(git_rerere_usage);

	string_list_clear(&merge_rr, 1);
	return 0;
}
