		putchar('\n');

	if (revs.verbose_header) {
		struct strbuf buf;
		strbuf_init(&buf, 0);
		pretty_print_commit(revs.commit_format, commit,
					&buf, revs.abbrev, NULL, NULL, revs.date_mode);
		printf("%s%c", buf.buf, hdr_termination);
		strbuf_release(&buf);
	}
	maybe_flush_or_die(stdout, "stdout");
	if (commit->parents) {
