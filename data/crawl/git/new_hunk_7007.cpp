	return 0;
}

int cmd_rerere(int argc, const char **argv, const char *prefix)
{
	struct path_list merge_rr = { NULL, 0, 0, 1 };
	int i, fd;

	if (argc < 2)
		return rerere();

	fd = setup_rerere(&merge_rr);
	if (fd < 0)
		return 0;

	if (!strcmp(argv[1], "clear")) {
		for (i = 0; i < merge_rr.nr; i++) {
			const char *name = (const char *)merge_rr.items[i].util;
			if (!has_resolution(name))
				unlink_rr_item(name);
		}
		unlink(git_path("rr-cache/MERGE_RR"));
	} else if (!strcmp(argv[1], "gc"))
		garbage_collect(&merge_rr);
	else if (!strcmp(argv[1], "status"))
