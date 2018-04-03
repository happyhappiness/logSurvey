		initial_commit ? " (root-commit)" : "");

	if (!log_tree_commit(&rev, commit)) {
		struct pretty_print_context ctx = {0};
		struct strbuf buf = STRBUF_INIT;
		ctx.date_mode = DATE_NORMAL;
		format_commit_message(commit, format + 7, &buf, &ctx);
		printf("%s\n", buf.buf);
		strbuf_release(&buf);
	}
