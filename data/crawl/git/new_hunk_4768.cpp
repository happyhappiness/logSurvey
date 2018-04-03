	config_fetch_recurse_submodules = value;
}

static void submodule_collect_changed_cb(struct diff_queue_struct *q,
					 struct diff_options *options,
					 void *data)
{
	int i;
	for (i = 0; i < q->nr; i++) {
		struct diff_filepair *p = q->queue[i];
		if (!S_ISGITLINK(p->two->mode))
			continue;

		if (S_ISGITLINK(p->one->mode)) {
			/* NEEDSWORK: We should honor the name configured in
			 * the .gitmodules file of the commit we are examining
			 * here to be able to correctly follow submodules
			 * being moved around. */
			struct string_list_item *path;
			path = unsorted_string_list_lookup(&changed_submodule_paths, p->two->path);
			if (!path)
				string_list_append(&changed_submodule_paths, xstrdup(p->two->path));
		} else {
			/* Submodule is new or was moved here */
			/* NEEDSWORK: When the .git directories of submodules
			 * live inside the superprojects .git directory some
			 * day we should fetch new submodules directly into
			 * that location too when config or options request
			 * that so they can be checked out from there. */
			continue;
		}
	}
}

void check_for_new_submodule_commits(unsigned char new_sha1[20])
{
	struct rev_info rev;
	struct commit *commit;
	const char *argv[] = {NULL, NULL, "--not", "--all", NULL};
	int argc = ARRAY_SIZE(argv) - 1;

	init_revisions(&rev, NULL);
	argv[1] = xstrdup(sha1_to_hex(new_sha1));
	setup_revisions(argc, argv, &rev, NULL);
	if (prepare_revision_walk(&rev))
		die("revision walk setup failed");

	/*
	 * Collect all submodules (whether checked out or not) for which new
	 * commits have been recorded upstream in "changed_submodule_paths".
	 */
	while ((commit = get_revision(&rev))) {
		struct commit_list *parent = commit->parents;
		while (parent) {
			struct diff_options diff_opts;
			diff_setup(&diff_opts);
			diff_opts.output_format |= DIFF_FORMAT_CALLBACK;
			diff_opts.format_callback = submodule_collect_changed_cb;
			if (diff_setup_done(&diff_opts) < 0)
				die("diff_setup_done failed");
			diff_tree_sha1(parent->item->object.sha1, commit->object.sha1, "", &diff_opts);
			diffcore_std(&diff_opts);
			diff_flush(&diff_opts);
			parent = parent->next;
		}
	}
	free((char *)argv[1]);
}

int fetch_populated_submodules(int num_options, const char **options,
			       const char *prefix, int ignore_config,
			       int quiet)
{
	int i, result = 0, argc = 0, default_argc;
	struct child_process cp;
	const char **argv;
	struct string_list_item *name_for_path;
	const char *work_tree = get_git_work_tree();
	if (!work_tree)
		goto out;

	if (!the_index.initialized)
		if (read_cache() < 0)
			die("index file corrupt");

	/* 6: "fetch" (options) --recurse-submodules-default default "--submodule-prefix" prefix NULL */
	argv = xcalloc(num_options + 6, sizeof(const char *));
	argv[argc++] = "fetch";
	for (i = 0; i < num_options; i++)
		argv[argc++] = options[i];
	argv[argc++] = "--recurse-submodules-default";
	default_argc = argc++;
	argv[argc++] = "--submodule-prefix";

	memset(&cp, 0, sizeof(cp));
