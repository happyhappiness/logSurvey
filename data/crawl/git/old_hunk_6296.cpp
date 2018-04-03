		OPT__DRY_RUN(&dry_run),
		OPT_END()
	};
	struct ref_states states;
	const char *dangling_msg;

	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);

	if (argc < 1)
		usage_with_options(builtin_remote_usage, options);

	dangling_msg = (dry_run
			? " %s will become dangling!\n"
			: " %s has become dangling!\n");

	memset(&states, 0, sizeof(states));
	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, GET_REF_STATES);

		if (states.stale.nr) {
			printf("Pruning %s\n", *argv);
			printf("URL: %s\n",
			       states.remote->url_nr
			       ? states.remote->url[0]
			       : "(no URL)");
		}

		for (i = 0; i < states.stale.nr; i++) {
			const char *refname = states.stale.items[i].util;

			if (!dry_run)
				result |= delete_ref(refname, NULL, 0);

			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
			       abbrev_ref(refname, "refs/remotes/"));
			warn_dangling_symref(dangling_msg, refname);
		}

		free_remote_ref_states(&states);
	}

	return result;
}
