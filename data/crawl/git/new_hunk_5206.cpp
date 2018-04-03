	return 0;
}

static void prepare_revs(struct rev_info *revs)
{
	int argc = 0;
	int i;
	const char **argv = xmalloc((commit_argc + 4) * sizeof(*argv));

	argv[argc++] = NULL;
	argv[argc++] = "--no-walk";
	if (action != REVERT)
		argv[argc++] = "--reverse";
	for (i = 0; i < commit_argc; i++)
		argv[argc++] = commit_argv[i];
	argv[argc++] = NULL;

	init_revisions(revs, NULL);
	setup_revisions(argc - 1, argv, revs, NULL);
	if (prepare_revision_walk(revs))
		die("revision walk setup failed");

	if (!revs->commits)
		die("empty commit set passed");

	free(argv);
}

static int revert_or_cherry_pick(int argc, const char **argv)
{
	struct rev_info revs;

	git_config(git_default_config, NULL);
	me = action == REVERT ? "revert" : "cherry-pick";
	setenv(GIT_REFLOG_ACTION, me, 0);
