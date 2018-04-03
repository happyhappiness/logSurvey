	return r;
}

int cmd_merge_base(int argc, const char **argv, const char *prefix)
{
	struct commit **rev;
	int rev_nr = 0;
	int show_all = 0;

	struct option options[] = {
		OPT_BOOLEAN('a', "all", &show_all, "outputs all common ancestors"),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, options, merge_base_usage, 0);
	if (argc < 2)
		usage_with_options(merge_base_usage, options);
	rev = xmalloc(argc * sizeof(*rev));
	while (argc-- > 0)
		rev[rev_nr++] = get_commit_reference(*argv++);
