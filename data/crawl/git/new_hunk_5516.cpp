	return result;
}

static int get_remote_default(const char *key, const char *value, void *priv)
{
	if (strcmp(key, "remotes.default") == 0) {
		int *found = priv;
		*found = 1;
	}
	return 0;
}

static int update(int argc, const char **argv)
{
	int i, prune = 0;
	struct option options[] = {
		OPT_GROUP("update specific options"),
		OPT_BOOLEAN('p', "prune", &prune,
			    "prune remotes after fetching"),
		OPT_END()
	};
	const char **fetch_argv;
	int fetch_argc = 0;
	int default_defined = 0;

	fetch_argv = xmalloc(sizeof(char *) * (argc+5));

	argc = parse_options(argc, argv, NULL, options, builtin_remote_usage,
			     PARSE_OPT_KEEP_ARGV0);

	fetch_argv[fetch_argc++] = "fetch";

	if (prune)
		fetch_argv[fetch_argc++] = "--prune";
	if (verbose)
		fetch_argv[fetch_argc++] = "-v";
	if (argc < 2) {
		fetch_argv[fetch_argc++] = "default";
	} else {
		fetch_argv[fetch_argc++] = "--multiple";
		for (i = 1; i < argc; i++)
			fetch_argv[fetch_argc++] = argv[i];
	}

	if (strcmp(fetch_argv[fetch_argc-1], "default") == 0) {
		git_config(get_remote_default, &default_defined);
		if (!default_defined)
			fetch_argv[fetch_argc-1] = "--all";
	}

	fetch_argv[fetch_argc] = NULL;

	return run_command_v_opt(fetch_argv, RUN_GIT_CMD);
}

static int get_one_entry(struct remote *remote, void *priv)