		string_list_clear(info.list, 0);

		/* git push info */
		if (states.remote->mirror)
			printf("  Local refs will be mirrored by 'git push'\n");

		info.width = info.width2 = 0;
		for_each_string_list(add_push_to_show_info, &states.push, &info);
		sort_string_list(info.list);
		if (info.list->nr)
			printf("  Local ref%s configured for 'git push'%s:\n",
				info.list->nr > 1 ? "s" : "",
				no_query ? " (status not queried)" : "");
		for_each_string_list(show_push_info_item, info.list, &info);
		string_list_clear(info.list, 0);

		free_remote_ref_states(&states);
	}
