
		get_remote_ref_states(*argv, &states, query_flag);

		printf("* remote %s\n", *argv);
		if (states.remote->url_nr) {
			for (i=0; i < states.remote->url_nr; i++)
				printf("  URL: %s\n", states.remote->url[i]);
		} else
			printf("  URL: %s\n", "(no URL)");
		if (no_query)
			printf("  HEAD branch: (not queried)\n");
		else if (!states.heads.nr)