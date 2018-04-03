
	read_mailmap(&mailmap, ".mailmap", &common_repo_prefix);

	if (rev.pending.nr == 0) {
		if (isatty(0))
			fprintf(stderr, "(reading log to summarize from standard input)\n");
		read_from_stdin(&list);
	}
	else
