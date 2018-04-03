	}
}

int cmd_name_rev(int argc, const char **argv, const char *prefix)
{
	struct object_array revs = { 0, 0, NULL };
	int as_is = 0, all = 0, transform_stdin = 0;
	struct name_ref_data data = { 0, 0, NULL };

	git_config(git_default_config);

	if (argc < 2)
		usage(name_rev_usage);

	for (--argc, ++argv; argc; --argc, ++argv) {
		unsigned char sha1[20];
		struct object *o;
		struct commit *commit;

		if (!as_is && (*argv)[0] == '-') {
			if (!strcmp(*argv, "--")) {
				as_is = 1;
				continue;
			} else if (!strcmp(*argv, "--name-only")) {
				data.name_only = 1;
				continue;
			} else if (!strcmp(*argv, "--tags")) {
				data.tags_only = 1;
				continue;
			} else  if (!prefixcmp(*argv, "--refs=")) {
				data.ref_filter = *argv + 7;
				continue;
			} else if (!strcmp(*argv, "--all")) {
				if (argc > 1)
					die("Specify either a list, or --all, not both!");
				all = 1;
				cutoff = 0;
				continue;
			} else if (!strcmp(*argv, "--stdin")) {
				if (argc > 1)
					die("Specify either a list, or --stdin, not both!");
				transform_stdin = 1;
				cutoff = 0;
				continue;
			}
			usage(name_rev_usage);
		}

		if (get_sha1(*argv, sha1)) {
			fprintf(stderr, "Could not get sha1 for %s. Skipping.\n",
					*argv);
