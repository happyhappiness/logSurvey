		argc--;
	}

	if (show_in_pager) {
		const char *pager = git_pager(1);
		if (!pager) {
			show_in_pager = 0;
		} else {
			opt.name_only = 1;
			opt.null_following_name = 1;
			opt.output_priv = &path_list;
			opt.output = append_path;
			string_list_append(pager, &path_list);
			use_threads = 0;
		}
	}

	if (!opt.pattern_list)
		die("no pattern given.");
	if (!opt.fixed && opt.ignore_case)
