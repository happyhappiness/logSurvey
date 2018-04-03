	prepare_revision_walk(&revs);
	commit = get_revision(&revs);
	if (commit) {
		strbuf_release(&buf);
		format_commit_message(commit, "%an <%ae>", &buf, DATE_NORMAL);
		return strbuf_detach(&buf, NULL);
	}
	die("No existing author found with '%s'", name);
