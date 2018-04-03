	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, !no_query);

		for (i = 0; i < states.stale.nr; i++) {
			const char *refname = states.stale.items[i].util;
			result |= delete_ref(refname, NULL);
		}

		/* NEEDSWORK: free remote */
