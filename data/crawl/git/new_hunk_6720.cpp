	rev.diffopt.break_opt = 0;
	diff_setup_done(&rev.diffopt);

	printf("Created %s", initial_commit ? "root-commit " : "");

	if (!log_tree_commit(&rev, commit)) {
		struct strbuf buf = STRBUF_INIT;