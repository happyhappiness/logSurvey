		initial_commit ? " (root-commit)" : "");

	if (!log_tree_commit(&rev, commit)) {
		struct strbuf buf = STRBUF_INIT;
		format_commit_message(commit, format + 7, &buf, DATE_NORMAL);
		printf("%s\n", buf.buf);
		strbuf_release(&buf);
	}
