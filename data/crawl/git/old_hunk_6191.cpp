
static int update(int argc, const char **argv)
{
	int i, result = 0;
	struct string_list list = { NULL, 0, 0, 0 };
	static const char *default_argv[] = { NULL, "default", NULL };

	if (argc < 2) {
		argc = 2;
		argv = default_argv;
	}

	remote_group.list = &list;
	for (i = 1; i < argc; i++) {
		remote_group.name = argv[i];
		result = git_config(get_remote_group, NULL);
	}

	if (!result && !list.nr  && argc == 2 && !strcmp(argv[1], "default"))
		result = for_each_remote(get_one_remote_for_update, &list);

	for (i = 0; i < list.nr; i++)
		result |= fetch_remote(list.items[i].string);

	/* all names were strdup()ed or strndup()ed */
	list.strdup_strings = 1;
