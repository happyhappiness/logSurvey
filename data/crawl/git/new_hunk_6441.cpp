	if (argc < 1)
		return show_all();

	if (!no_query)
		query_flag = (GET_REF_STATES | GET_HEAD_NAMES);

	memset(&states, 0, sizeof(states));
	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, query_flag);

		printf("* remote %s\n  URL: %s\n", *argv,
			states.remote->url_nr > 0 ?
				states.remote->url[0] : "(no URL)");
		if (no_query)
			printf("  HEAD branch: (not queried)\n");
		else if (!states.heads.nr)
			printf("  HEAD branch: (unknown)\n");
		else if (states.heads.nr == 1)
			printf("  HEAD branch: %s\n", states.heads.items[0].string);
		else {
			printf("  HEAD branch (remote HEAD is ambiguous,"
			       " may be one of the following):\n");
			for (i = 0; i < states.heads.nr; i++)
				printf("    %s\n", states.heads.items[i].string);
		}

		for (i = 0; i < branch_list.nr; i++) {
			struct string_list_item *branch = branch_list.items + i;
