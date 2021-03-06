 				handle_refs(revs, flags, for_each_remote_ref);
 				continue;
 			}
-			if (!strcmp(arg, "--first-parent")) {
-				revs->first_parent_only = 1;
-				continue;
-			}
 			if (!strcmp(arg, "--reflog")) {
 				handle_reflog(revs, flags);
 				continue;
 			}
-			if (!strcmp(arg, "-g") ||
-					!strcmp(arg, "--walk-reflogs")) {
-				init_reflog_walk(&revs->reflog_info);
-				continue;
-			}
 			if (!strcmp(arg, "--not")) {
 				flags ^= UNINTERESTING;
 				continue;
 			}
-			if (!strcmp(arg, "--default")) {
-				if (++i >= argc)
-					die("bad --default argument");
-				def = argv[i];
-				continue;
-			}
-			if (!strcmp(arg, "--merge")) {
-				show_merge = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--topo-order")) {
-				revs->lifo = 1;
-				revs->topo_order = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--date-order")) {
-				revs->lifo = 0;
-				revs->topo_order = 1;
-				continue;
-			}
-			if (!prefixcmp(arg, "--early-output")) {
-				int count = 100;
-				switch (arg[14]) {
-				case '=':
-					count = atoi(arg+15);
-					/* Fallthrough */
-				case 0:
-					revs->topo_order = 1;
-					revs->early_output = count;
-					continue;
-				}
-			}
-			if (!strcmp(arg, "--parents")) {
-				revs->rewrite_parents = 1;
-				revs->print_parents = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--dense")) {
-				revs->dense = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--sparse")) {
-				revs->dense = 0;
-				continue;
-			}
-			if (!strcmp(arg, "--show-all")) {
-				revs->show_all = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--remove-empty")) {
-				revs->remove_empty_trees = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--no-merges")) {
-				revs->no_merges = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--boundary")) {
-				revs->boundary = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--left-right")) {
-				revs->left_right = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--cherry-pick")) {
-				revs->cherry_pick = 1;
-				revs->limited = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--objects")) {
-				revs->tag_objects = 1;
-				revs->tree_objects = 1;
-				revs->blob_objects = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--objects-edge")) {
-				revs->tag_objects = 1;
-				revs->tree_objects = 1;
-				revs->blob_objects = 1;
-				revs->edge_hint = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--unpacked")) {
-				revs->unpacked = 1;
-				free(revs->ignore_packed);
-				revs->ignore_packed = NULL;
-				revs->num_ignore_packed = 0;
-				continue;
-			}
-			if (!prefixcmp(arg, "--unpacked=")) {
-				revs->unpacked = 1;
-				add_ignore_packed(revs, arg+11);
-				continue;
-			}
-			if (!strcmp(arg, "-r")) {
-				revs->diff = 1;
-				DIFF_OPT_SET(&revs->diffopt, RECURSIVE);
-				continue;
-			}
-			if (!strcmp(arg, "-t")) {
-				revs->diff = 1;
-				DIFF_OPT_SET(&revs->diffopt, RECURSIVE);
-				DIFF_OPT_SET(&revs->diffopt, TREE_IN_RECURSIVE);
-				continue;
-			}
-			if (!strcmp(arg, "-m")) {
-				revs->ignore_merges = 0;
-				continue;
-			}
-			if (!strcmp(arg, "-c")) {
-				revs->diff = 1;
-				revs->dense_combined_merges = 0;
-				revs->combine_merges = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--cc")) {
-				revs->diff = 1;
-				revs->dense_combined_merges = 1;
-				revs->combine_merges = 1;
-				continue;
-			}
-			if (!strcmp(arg, "-v")) {
-				revs->verbose_header = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--pretty")) {
-				revs->verbose_header = 1;
-				get_commit_format(arg+8, revs);
-				continue;
-			}
-			if (!prefixcmp(arg, "--pretty=")) {
-				revs->verbose_header = 1;
-				get_commit_format(arg+9, revs);
-				continue;
-			}
-			if (!strcmp(arg, "--graph")) {
-				revs->topo_order = 1;
-				revs->rewrite_parents = 1;
-				revs->graph = graph_init(revs);
-				continue;
-			}
-			if (!strcmp(arg, "--root")) {
-				revs->show_root_diff = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--no-commit-id")) {
-				revs->no_commit_id = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--always")) {
-				revs->always_show_header = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--no-abbrev")) {
-				revs->abbrev = 0;
-				continue;
-			}
-			if (!strcmp(arg, "--abbrev")) {
-				revs->abbrev = DEFAULT_ABBREV;
-				continue;
-			}
-			if (!prefixcmp(arg, "--abbrev=")) {
-				revs->abbrev = strtoul(arg + 9, NULL, 10);
-				if (revs->abbrev < MINIMUM_ABBREV)
-					revs->abbrev = MINIMUM_ABBREV;
-				else if (revs->abbrev > 40)
-					revs->abbrev = 40;
-				continue;
-			}
-			if (!strcmp(arg, "--abbrev-commit")) {
-				revs->abbrev_commit = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--full-diff")) {
-				revs->diff = 1;
-				revs->full_diff = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--full-history")) {
-				revs->simplify_history = 0;
-				continue;
-			}
-			if (!strcmp(arg, "--relative-date")) {
-				revs->date_mode = DATE_RELATIVE;
-				continue;
-			}
-			if (!strncmp(arg, "--date=", 7)) {
-				revs->date_mode = parse_date_format(arg + 7);
-				continue;
-			}
-			if (!strcmp(arg, "--log-size")) {
-				revs->show_log_size = 1;
-				continue;
-			}
-
-			/*
-			 * Grepping the commit log
-			 */
-			if (!prefixcmp(arg, "--author=")) {
-				add_header_grep(revs, "author", arg+9);
-				continue;
-			}
-			if (!prefixcmp(arg, "--committer=")) {
-				add_header_grep(revs, "committer", arg+12);
-				continue;
-			}
-			if (!prefixcmp(arg, "--grep=")) {
-				add_message_grep(revs, arg+7);
-				continue;
-			}
-			if (!strcmp(arg, "--extended-regexp") ||
-			    !strcmp(arg, "-E")) {
-				regflags |= REG_EXTENDED;
-				continue;
-			}
-			if (!strcmp(arg, "--regexp-ignore-case") ||
-			    !strcmp(arg, "-i")) {
-				regflags |= REG_ICASE;
-				continue;
-			}
-			if (!strcmp(arg, "--fixed-strings") ||
-			    !strcmp(arg, "-F")) {
-				fixed = 1;
-				continue;
-			}
-			if (!strcmp(arg, "--all-match")) {
-				all_match = 1;
-				continue;
-			}
-			if (!prefixcmp(arg, "--encoding=")) {
-				arg += 11;
-				if (strcmp(arg, "none"))
-					git_log_output_encoding = xstrdup(arg);
-				else
-					git_log_output_encoding = "";
-				continue;
-			}
-			if (!strcmp(arg, "--reverse")) {
-				revs->reverse ^= 1;
-				continue;
-			}
 			if (!strcmp(arg, "--no-walk")) {
 				revs->no_walk = 1;
 				continue;
