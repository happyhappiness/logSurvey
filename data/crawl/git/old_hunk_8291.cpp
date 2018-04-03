		putchar('\n');

	if (revs.verbose_header) {
		static char pretty_header[16384];
		pretty_print_commit(revs.commit_format, commit, ~0,
				    pretty_header, sizeof(pretty_header),
				    revs.abbrev, NULL, NULL, revs.date_mode);
		printf("%s%c", pretty_header, hdr_termination);
	}
	fflush(stdout);
	if (commit->parents) {
