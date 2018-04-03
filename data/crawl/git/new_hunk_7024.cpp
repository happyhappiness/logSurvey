	revs->ignore_packed[num] = NULL;
}

int handle_revision_opt(struct rev_info *revs, int argc, const char **argv,
			int *unkc, const char **unkv)
{
	const char *arg = argv[0];

	/* pseudo revision arguments */
	if (!strcmp(arg, "--all") || !strcmp(arg, "--branches") ||
	    !strcmp(arg, "--tags") || !strcmp(arg, "--remotes") ||
	    !strcmp(arg, "--reflog") || !strcmp(arg, "--not") ||
	    !strcmp(arg, "--no-walk") || !strcmp(arg, "--do-walk"))
	{
		unkv[(*unkc)++] = arg;
		return 0;
	}

	if (!prefixcmp(arg, "--max-count=")) {
		revs->max_count = atoi(arg + 12);
	} else if (!prefixcmp(arg, "--skip=")) {
		revs->skip_count = atoi(arg + 7);
	} else if ((*arg == '-') && isdigit(arg[1])) {
	/* accept -<digit>, like traditional "head" */
		revs->max_count = atoi(arg + 1);
	} else if (!strcmp(arg, "-n")) {
		if (argc <= 1)
			return error("-n requires an argument");
		revs->max_count = atoi(argv[1]);
		return 2;
	} else if (!prefixcmp(arg, "-n")) {
		revs->max_count = atoi(arg + 2);
	} else if (!prefixcmp(arg, "--max-age=")) {
		revs->max_age = atoi(arg + 10);
	} else if (!prefixcmp(arg, "--since=")) {
		revs->max_age = approxidate(arg + 8);
	} else if (!prefixcmp(arg, "--after=")) {
		revs->max_age = approxidate(arg + 8);
	} else if (!prefixcmp(arg, "--min-age=")) {
		revs->min_age = atoi(arg + 10);
	} else if (!prefixcmp(arg, "--before=")) {
		revs->min_age = approxidate(arg + 9);
	} else if (!prefixcmp(arg, "--until=")) {
		revs->min_age = approxidate(arg + 8);
	} else if (!strcmp(arg, "--first-parent")) {
		revs->first_parent_only = 1;
	} else if (!strcmp(arg, "-g") || !strcmp(arg, "--walk-reflogs")) {
		init_reflog_walk(&revs->reflog_info);
	} else if (!strcmp(arg, "--default")) {
		if (argc <= 1)
			return error("bad --default argument");
		revs->def = argv[1];
		return 2;
	} else if (!strcmp(arg, "--merge")) {
		revs->show_merge = 1;
	} else if (!strcmp(arg, "--topo-order")) {
		revs->lifo = 1;
		revs->topo_order = 1;
	} else if (!strcmp(arg, "--date-order")) {
		revs->lifo = 0;
		revs->topo_order = 1;
	} else if (!prefixcmp(arg, "--early-output")) {
		int count = 100;
		switch (arg[14]) {
		case '=':
			count = atoi(arg+15);
			/* Fallthrough */
		case 0:
			revs->topo_order = 1;
		       revs->early_output = count;
		}
	} else if (!strcmp(arg, "--parents")) {
		revs->rewrite_parents = 1;
		revs->print_parents = 1;
	} else if (!strcmp(arg, "--dense")) {
		revs->dense = 1;
	} else if (!strcmp(arg, "--sparse")) {
		revs->dense = 0;
	} else if (!strcmp(arg, "--show-all")) {
		revs->show_all = 1;
	} else if (!strcmp(arg, "--remove-empty")) {
		revs->remove_empty_trees = 1;
	} else if (!strcmp(arg, "--no-merges")) {
		revs->no_merges = 1;
	} else if (!strcmp(arg, "--boundary")) {
		revs->boundary = 1;
	} else if (!strcmp(arg, "--left-right")) {
		revs->left_right = 1;
	} else if (!strcmp(arg, "--cherry-pick")) {
		revs->cherry_pick = 1;
		revs->limited = 1;
	} else if (!strcmp(arg, "--objects")) {
		revs->tag_objects = 1;
		revs->tree_objects = 1;
		revs->blob_objects = 1;
	} else if (!strcmp(arg, "--objects-edge")) {
		revs->tag_objects = 1;
		revs->tree_objects = 1;
		revs->blob_objects = 1;
		revs->edge_hint = 1;
	} else if (!strcmp(arg, "--unpacked")) {
		revs->unpacked = 1;
		free(revs->ignore_packed);
		revs->ignore_packed = NULL;
		revs->num_ignore_packed = 0;
	} else if (!prefixcmp(arg, "--unpacked=")) {
		revs->unpacked = 1;
		add_ignore_packed(revs, arg+11);
	} else if (!strcmp(arg, "-r")) {
		revs->diff = 1;
		DIFF_OPT_SET(&revs->diffopt, RECURSIVE);
	} else if (!strcmp(arg, "-t")) {
		revs->diff = 1;
		DIFF_OPT_SET(&revs->diffopt, RECURSIVE);
		DIFF_OPT_SET(&revs->diffopt, TREE_IN_RECURSIVE);
	} else if (!strcmp(arg, "-m")) {
		revs->ignore_merges = 0;
	} else if (!strcmp(arg, "-c")) {
		revs->diff = 1;
		revs->dense_combined_merges = 0;
		revs->combine_merges = 1;
	} else if (!strcmp(arg, "--cc")) {
		revs->diff = 1;
		revs->dense_combined_merges = 1;
		revs->combine_merges = 1;
	} else if (!strcmp(arg, "-v")) {
		revs->verbose_header = 1;
	} else if (!strcmp(arg, "--pretty")) {
		revs->verbose_header = 1;
		get_commit_format(arg+8, revs);
	} else if (!prefixcmp(arg, "--pretty=")) {
		revs->verbose_header = 1;
		get_commit_format(arg+9, revs);
	} else if (!strcmp(arg, "--graph")) {
		revs->topo_order = 1;
		revs->rewrite_parents = 1;
		revs->graph = graph_init(revs);
	} else if (!strcmp(arg, "--root")) {
		revs->show_root_diff = 1;
	} else if (!strcmp(arg, "--no-commit-id")) {
		revs->no_commit_id = 1;
	} else if (!strcmp(arg, "--always")) {
		revs->always_show_header = 1;
	} else if (!strcmp(arg, "--no-abbrev")) {
		revs->abbrev = 0;
	} else if (!strcmp(arg, "--abbrev")) {
		revs->abbrev = DEFAULT_ABBREV;
	} else if (!prefixcmp(arg, "--abbrev=")) {
		revs->abbrev = strtoul(arg + 9, NULL, 10);
		if (revs->abbrev < MINIMUM_ABBREV)
			revs->abbrev = MINIMUM_ABBREV;
		else if (revs->abbrev > 40)
			revs->abbrev = 40;
	} else if (!strcmp(arg, "--abbrev-commit")) {
		revs->abbrev_commit = 1;
	} else if (!strcmp(arg, "--full-diff")) {
		revs->diff = 1;
		revs->full_diff = 1;
	} else if (!strcmp(arg, "--full-history")) {
		revs->simplify_history = 0;
	} else if (!strcmp(arg, "--relative-date")) {
		revs->date_mode = DATE_RELATIVE;
	} else if (!strncmp(arg, "--date=", 7)) {
		revs->date_mode = parse_date_format(arg + 7);
	} else if (!strcmp(arg, "--log-size")) {
		revs->show_log_size = 1;
	}
	/*
	 * Grepping the commit log
	 */
	else if (!prefixcmp(arg, "--author=")) {
		add_header_grep(revs, "author", arg+9);
	} else if (!prefixcmp(arg, "--committer=")) {
		add_header_grep(revs, "committer", arg+12);
	} else if (!prefixcmp(arg, "--grep=")) {
		add_message_grep(revs, arg+7);
	} else if (!strcmp(arg, "--extended-regexp") || !strcmp(arg, "-E")) {
		if (revs->grep_filter)
			revs->grep_filter->regflags |= REG_EXTENDED;
	} else if (!strcmp(arg, "--regexp-ignore-case") || !strcmp(arg, "-i")) {
		if (revs->grep_filter)
			revs->grep_filter->regflags |= REG_ICASE;
	} else if (!strcmp(arg, "--fixed-strings") || !strcmp(arg, "-F")) {
		if (revs->grep_filter)
			revs->grep_filter->fixed = 1;
	} else if (!strcmp(arg, "--all-match")) {
		if (revs->grep_filter)
			revs->grep_filter->all_match = 1;
	} else if (!prefixcmp(arg, "--encoding=")) {
		arg += 11;
		if (strcmp(arg, "none"))
			git_log_output_encoding = xstrdup(arg);
		else
			git_log_output_encoding = "";
	} else if (!strcmp(arg, "--reverse")) {
		revs->reverse ^= 1;
	} else if (!strcmp(arg, "--children")) {
		revs->children.name = "children";
		revs->limited = 1;
	} else {
		int opts = diff_opt_parse(&revs->diffopt, argv, argc);
		if (!opts)
			unkv[(*unkc)++] = arg;
		return opts;
	}

	return 1;
}

/*
 * Parse revision information, filling in the "rev_info" structure,
 * and removing the used arguments from the argument list.
