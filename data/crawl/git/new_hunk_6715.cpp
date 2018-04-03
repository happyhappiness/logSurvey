	rev.diffopt.break_opt = 0;
	diff_setup_done(&rev.diffopt);

	printf("[%s%s]: created ",
		!prefixcmp(head, "refs/heads/") ?
			head + 11 :
			!strcmp(head, "HEAD") ?
				"detached HEAD" :
				head,
		initial_commit ? " (root-commit)" : "");

	if (!log_tree_commit(&rev, commit)) {
		struct strbuf buf = STRBUF_INIT;
		format_commit_message(commit, format + 7, &buf, DATE_NORMAL);
		printf("%s\n", buf.buf);
		strbuf_release(&buf);
	}
}

static int git_commit_config(const char *k, const char *v, void *cb)