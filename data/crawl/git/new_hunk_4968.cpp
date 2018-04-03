	strbuf_release(&sb);
}

int fetch_populated_submodules(int num_options, const char **options,
			       const char *prefix, int quiet)
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

	argv = xcalloc(num_options + 5, sizeof(const char *));
	argv[argc++] = "fetch";
	for (i = 0; i < num_options; i++)
		argv[argc++] = options[i];
	argv[argc++] = "--submodule-prefix";

	memset(&cp, 0, sizeof(cp));
	cp.argv = argv;
	cp.env = local_repo_env;
	cp.git_cmd = 1;
	cp.no_stdin = 1;

	for (i = 0; i < active_nr; i++) {
		struct strbuf submodule_path = STRBUF_INIT;
		struct strbuf submodule_git_dir = STRBUF_INIT;
		struct strbuf submodule_prefix = STRBUF_INIT;
		struct cache_entry *ce = active_cache[i];
		const char *git_dir, *name;

		if (!S_ISGITLINK(ce->ce_mode))
			continue;

		name = ce->name;
		name_for_path = unsorted_string_list_lookup(&config_name_for_path, ce->name);
		if (name_for_path)
			name = name_for_path->util;

		strbuf_addf(&submodule_path, "%s/%s", work_tree, ce->name);
		strbuf_addf(&submodule_git_dir, "%s/.git", submodule_path.buf);
		strbuf_addf(&submodule_prefix, "%s%s/", prefix, ce->name);
		git_dir = read_gitfile_gently(submodule_git_dir.buf);
		if (!git_dir)
			git_dir = submodule_git_dir.buf;
		if (is_directory(git_dir)) {
			if (!quiet)
				printf("Fetching submodule %s%s\n", prefix, ce->name);
			cp.dir = submodule_path.buf;
			argv[argc] = submodule_prefix.buf;
			if (run_command(&cp))
				result = 1;
		}
		strbuf_release(&submodule_path);
		strbuf_release(&submodule_git_dir);
		strbuf_release(&submodule_prefix);
	}
	free(argv);
	return result;
}

unsigned is_submodule_modified(const char *path, int ignore_untracked)
{
	ssize_t len;
