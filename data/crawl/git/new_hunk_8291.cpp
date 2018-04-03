		putchar('\n');

	if (revs.verbose_header) {
		char *buf = NULL;
		unsigned long buflen = 0;
		pretty_print_commit(revs.commit_format, commit, ~0,
				    &buf, &buflen,
				    revs.abbrev, NULL, NULL, revs.date_mode);
		printf("%s%c", buf, hdr_termination);
		free(buf);
	}
	fflush(stdout);
	if (commit->parents) {
