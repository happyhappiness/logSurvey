				printf("    %s\n", states.heads.items[i].string);
		}

		/* remote branch info */
		info.width = 0;
		for_each_string_list(add_remote_to_show_info, &states.new, &info);
		for_each_string_list(add_remote_to_show_info, &states.tracked, &info);
		for_each_string_list(add_remote_to_show_info, &states.stale, &info);
		if (info.list->nr)
			printf("  Remote branch%s:%s\n",
			       info.list->nr > 1 ? "es" : "",
				no_query ? " (status not queried)" : "");
		for_each_string_list(show_remote_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		/* git pull info */
		info.width = 0;
		info.any_rebase = 0;
		for_each_string_list(add_local_to_show_info, &branch_list, &info);
		if (info.list->nr)
			printf("  Local branch%s configured for 'git pull':\n",
			       info.list->nr > 1 ? "es" : "");
		for_each_string_list(show_local_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		/* git push info */
		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n",
				states.remote->push_refspec_nr > 1 ?
