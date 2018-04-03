	if (query) {
		transport = transport_get(NULL, states->remote->url_nr > 0 ?
			states->remote->url[0] : NULL);
		ref = transport_get_remote_refs(transport);
		transport_disconnect(transport);

		get_ref_states(ref, states);
	}

	return 0;
}

static int append_ref_to_tracked_list(const char *refname,
	const unsigned char *sha1, int flags, void *cb_data)
{
	struct ref_states *states = cb_data;
	struct refspec refspec;

	memset(&refspec, 0, sizeof(refspec));
	refspec.dst = (char *)refname;
	if (!remote_find_tracking(states->remote, &refspec))
		string_list_append(abbrev_branch(refspec.src), &states->tracked);

	return 0;
}

static int show(int argc, const char **argv)
{
	int no_query = 0, result = 0;
	struct option options[] = {
		OPT_GROUP("show specific options"),
		OPT_BOOLEAN('n', NULL, &no_query, "do not query remotes"),
		OPT_END()
	};
	struct ref_states states;

	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);

	if (argc < 1)
		return show_all();

	memset(&states, 0, sizeof(states));
	for (; argc; argc--, argv++) {
		int i;

		get_remote_ref_states(*argv, &states, !no_query);

		printf("* remote %s\n  URL: %s\n", *argv,
			states.remote->url_nr > 0 ?
				states.remote->url[0] : "(no URL)");

		for (i = 0; i < branch_list.nr; i++) {
			struct string_list_item *branch = branch_list.items + i;
			struct branch_info *info = branch->util;
			int j;

			if (!info->merge.nr || strcmp(*argv, info->remote))
				continue;
			printf("  Remote branch%s merged with 'git pull' "
				"while on branch %s\n   ",
				info->merge.nr > 1 ? "es" : "",
				branch->string);
			for (j = 0; j < info->merge.nr; j++)
				printf(" %s", info->merge.items[j].string);
			printf("\n");
		}

		if (!no_query) {
			show_list("  New remote branch%s (next fetch "
				"will store in remotes/%s)",
				&states.new, states.remote->name);
			show_list("  Stale tracking branch%s (use 'git remote "
				"prune')", &states.stale, "");
		}

		if (no_query)
			for_each_ref(append_ref_to_tracked_list, &states);
		show_list("  Tracked remote branch%s", &states.tracked, "");

		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n",
				states.remote->push_refspec_nr > 1 ?
					"es" : "");
			for (i = 0; i < states.remote->push_refspec_nr; i++) {
				struct refspec *spec = states.remote->push + i;
				printf("    %s%s%s%s\n",
				       spec->force ? "+" : "",
				       abbrev_branch(spec->src),
				       spec->dst ? ":" : "",
				       spec->dst ? abbrev_branch(spec->dst) : "");
			}
		}

		/* NEEDSWORK: free remote */
		string_list_clear(&states.new, 0);
		string_list_clear(&states.stale, 0);
		string_list_clear(&states.tracked, 0);
	}

	return result;
}

