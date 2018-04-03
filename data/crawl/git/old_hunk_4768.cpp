	config_fetch_recurse_submodules = value;
}

int fetch_populated_submodules(int num_options, const char **options,
			       const char *prefix, int ignore_config,
			       int quiet)
{
	int i, result = 0, argc = 0;
	struct child_process cp;
	const char **argv;
	struct string_list_item *name_for_path;
	const char *work_tree = get_git_work_tree();
	if (!work_tree)
		return 0;

	if (!the_index.initialized)
		if (read_cache() < 0)
			die("index file corrupt");

	/* 4: "fetch" (options) "--submodule-prefix" prefix NULL */
	argv = xcalloc(num_options + 4, sizeof(const char *));
	argv[argc++] = "fetch";
	for (i = 0; i < num_options; i++)
		argv[argc++] = options[i];
	argv[argc++] = "--submodule-prefix";

	memset(&cp, 0, sizeof(cp));
