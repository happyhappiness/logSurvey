	}
}

static char const * const name_rev_usage[] = {
	"git-name-rev [options] ( --all | --stdin | <commit>... )",
	NULL
};

int cmd_name_rev(int argc, const char **argv, const char *prefix)
{
	struct object_array revs = { 0, 0, NULL };
	int all = 0, transform_stdin = 0;
	struct name_ref_data data = { 0, 0, NULL };
	struct option opts[] = {
		OPT_BOOLEAN(0, "name-only", &data.name_only, "print only names (no SHA-1)"),
		OPT_BOOLEAN(0, "tags", &data.tags_only, "only use tags to name the commits"),
		OPT_STRING(0, "refs", &data.ref_filter, "pattern",
				   "only use refs matching <pattern>"),
		OPT_GROUP(""),
		OPT_BOOLEAN(0, "all", &all, "list all commits reachable from all refs"),
		OPT_BOOLEAN(0, "stdin", &transform_stdin, "read from stdin"),
		OPT_END(),
	};

	git_config(git_default_config);
	argc = parse_options(argc, argv, opts, name_rev_usage, 0);
	if (!!all + !!transform_stdin + !!argc > 1) {
		error("Specify either a list, or --all, not both!");
		usage_with_options(name_rev_usage, opts);
	}
	if (all || transform_stdin)
		cutoff = 0;

	for (; argc; argc--, argv++) {
		unsigned char sha1[20];
		struct object *o;
		struct commit *commit;

		if (get_sha1(*argv, sha1)) {
			fprintf(stderr, "Could not get sha1 for %s. Skipping.\n",
					*argv);
