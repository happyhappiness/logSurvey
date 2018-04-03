int diff_result_code(struct diff_options *opt, int status)
{
	int result = 0;

	diff_warn_rename_limit("diff.renamelimit",
			       opt->needed_rename_limit,
			       opt->degraded_cc_to_c);
	if (!DIFF_OPT_TST(opt, EXIT_WITH_STATUS) &&
	    !(opt->output_format & DIFF_FORMAT_CHECKDIFF))
		return status;
