
static int update(int argc, const char **argv)
{
	int i, result = 0, prune = 0;
	struct string_list list = { NULL, 0, 0, 0 };
	static const char *default_argv[] = { NULL, "default", NULL };
	struct option options[] = {
		OPT_GROUP("update specific options"),
		OPT_BOOLEAN('p', "prune", &prune,
			    "prune remotes after fecthing"),
		OPT_END()
	};

	argc = parse_options(argc, argv, options, builtin_remote_usage,
			     PARSE_OPT_KEEP_ARGV0);
	if (argc < 2) {
		argc = 2;
		argv = default_argv;
	}

	remote_group.list = &list;
	for (i = 1; i < argc; i++) {
		int groups_found = 0;
		remote_group.name = argv[i];
		result = git_config(get_remote_group, &groups_found);
		if (!groups_found && (i != 1 || strcmp(argv[1], "default"))) {
			struct remote *remote;
			if (!remote_is_configured(argv[i]))
				die("No such remote or remote group: %s",
				    argv[i]);
			remote = remote_get(argv[i]);
			string_list_append(remote->name, remote_group.list);
		}
	}

	if (!result && !list.nr  && argc == 2 && !strcmp(argv[1], "default"))
		result = for_each_remote(get_one_remote_for_update, &list);

	for (i = 0; i < list.nr; i++) {
		int err = fetch_remote(list.items[i].string);
		result |= err;
		if (!err && prune)
			result |= prune_remote(list.items[i].string, 0);
	}

	/* all names were strdup()ed or strndup()ed */
	list.strdup_strings = 1;
