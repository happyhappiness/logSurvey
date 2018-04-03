	if (prepare_revision_walk(&rev))
		die("revision walk setup failed");

	strbuf_addstr(&out, "Squashed commit of the following:\n");
	while ((commit = get_revision(&rev)) != NULL) {
		strbuf_addch(&out, '\n');
		strbuf_addf(&out, "commit %s\n",
			sha1_to_hex(commit->object.sha1));
		pretty_print_commit(rev.commit_format, commit, &out, rev.abbrev,
			NULL, NULL, rev.date_mode, 0);
	}
	if (write(fd, out.buf, out.len) < 0)
		die_errno("Writing SQUASH_MSG");
