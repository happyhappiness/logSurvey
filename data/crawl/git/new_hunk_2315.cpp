	ctx.output_encoding = get_log_output_encoding();

	format_commit_message(commit, "%an <%ae>", &author, &ctx);
	if (!log->summary) {
		if (log->user_format)
			pretty_print_commit(&ctx, commit, &oneline);
