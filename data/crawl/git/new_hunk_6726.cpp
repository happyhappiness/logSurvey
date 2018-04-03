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
			printf("  Local branch%s pushed with 'git push'\n   ",