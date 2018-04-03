
int cmd_prune(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	const struct option options[] = {
		OPT_BOOLEAN('n', NULL, &show_only,
			    "do not remove, show only"),
		OPT_DATE(0, "expire", &expire,
			 "expire objects older than <time>"),
		OPT_END()
	};

	save_commit_buffer = 0;
	init_revisions(&revs, prefix);

	argc = parse_options(argc, argv, options, prune_usage, 0);
	if (argc)
		die ("unrecognized argument: %s", name);
	mark_reachable_objects(&revs, 1);
	prune_object_dir(get_object_directory());

	sync();