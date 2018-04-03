	}

	if (verbose) {
		commit = lookup_commit(item->sha1);
		if (commit && !parse_commit(commit))
			pretty_print_commit(CMIT_FMT_ONELINE, commit, ~0,
					    subject, sizeof(subject), 0,
					    NULL, NULL, 0);
		else
			strcpy(subject, " **** invalid ref ****");
		printf("%c %s%-*s%s %s %s\n", c, branch_get_color(color),
		       maxwidth, item->name,
		       branch_get_color(COLOR_BRANCH_RESET),
		       find_unique_abbrev(item->sha1, abbrev), subject);
	} else {
		printf("%c %s%s%s\n", c, branch_get_color(color), item->name,
		       branch_get_color(COLOR_BRANCH_RESET));
