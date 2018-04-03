int diff_result_code(struct diff_options *opt, int status)
{
	int result = 0;
	if (!DIFF_OPT_TST(opt, EXIT_WITH_STATUS) &&
	    !(opt->output_format & DIFF_FORMAT_CHECKDIFF))
		return status;
