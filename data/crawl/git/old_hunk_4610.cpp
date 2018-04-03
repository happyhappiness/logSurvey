	}

	if (show_in_pager && (cached || list.nr))
		die("--open-files-in-pager only works on the worktree");

	if (show_in_pager && opt.pattern_list && !opt.pattern_list->next) {
		const char *pager = path_list.items[0].string;
