	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, 1);

		if (states.stale.nr) {
			printf("Pruning %s\n", *argv);
