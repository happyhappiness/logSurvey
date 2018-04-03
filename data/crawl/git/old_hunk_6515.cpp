	rev.diffopt.break_opt = 0;
	diff_setup_done(&rev.diffopt);

	printf("[%s%s]: created ",
		!prefixcmp(head, "refs/heads/") ?
			head + 11 :
			!strcmp(head, "HEAD") ?