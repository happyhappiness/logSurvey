
int cmd_prune(int argc, const char **argv, const char *prefix)
{
	int i;
	struct rev_info revs;

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!strcmp(arg, "-n")) {
			show_only = 1;
			continue;
		}
		if (!strcmp(arg, "--expire")) {
			if (++i < argc) {
				expire = approxidate(argv[i]);
				continue;
			}
		}
		else if (!prefixcmp(arg, "--expire=")) {
			expire = approxidate(arg + 9);
			continue;
		}
		usage(prune_usage);
	}

	save_commit_buffer = 0;
	init_revisions(&revs, prefix);
	mark_reachable_objects(&revs, 1);

	prune_object_dir(get_object_directory());

	sync();