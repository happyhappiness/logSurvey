{
	int result = 0;

	diff_warn_rename_limit("diff.renameLimit",
			       opt->needed_rename_limit,
			       opt->degraded_cc_to_c);
	if (!DIFF_OPT_TST(opt, EXIT_WITH_STATUS) &&