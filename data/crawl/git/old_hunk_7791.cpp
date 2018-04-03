		strbuf_release(&buf);
	}
	maybe_flush_or_die(stdout, "stdout");
	if (commit->parents) {
		free_commit_list(commit->parents);
		commit->parents = NULL;
