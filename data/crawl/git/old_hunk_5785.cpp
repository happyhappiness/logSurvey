		argc--;
	}

	if (opt.color && !opt.color_external)
		external_grep_allowed = 0;
	if (!opt.pattern_list)
		die("no pattern given.");
