	initialized_fetch_ref_tips = 0;
}

int fetch_populated_submodules(const struct argv_array *options,
			       const char *prefix, int command_line_option,
			       int quiet)
{
	int i, result = 0;
	struct child_process cp = CHILD_PROCESS_INIT;
	struct argv_array argv = ARGV_ARRAY_INIT;
	const char *work_tree = get_git_work_tree();
	if (!work_tree)
		goto out;

	if (read_cache() < 0)
		die("index file corrupt");

	argv_array_push(&argv, "fetch");
	for (i = 0; i < options->argc; i++)
		argv_array_push(&argv, options->argv[i]);
	argv_array_push(&argv, "--recurse-submodules-default");
	/* default value, "--submodule-prefix" and its value are added later */

	cp.env = local_repo_env;
	cp.git_cmd = 1;
	cp.no_stdin = 1;

	calculate_changed_submodule_paths();

	for (i = 0; i < active_nr; i++) {
		struct strbuf submodule_path = STRBUF_INIT;
		struct strbuf submodule_git_dir = STRBUF_INIT;
		struct strbuf submodule_prefix = STRBUF_INIT;
		const struct cache_entry *ce = active_cache[i];
		const char *git_dir, *default_argv;
		const struct submodule *submodule;

