
	read_mailmap(&mailmap, ".mailmap", &common_repo_prefix);

	/* assume HEAD if from a tty */
	if (!rev.pending.nr && isatty(0))
		add_head_to_pending(&rev);
	if (rev.pending.nr == 0) {
		read_from_stdin(&list);
	}
	else
