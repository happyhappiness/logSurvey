	rev.diffopt.break_opt = 0;
	diff_setup_done(&rev.diffopt);

	printf("Created %scommit ", initial_commit ? "initial " : "");

	if (!log_tree_commit(&rev, commit)) {
		struct strbuf buf = STRBUF_INIT;