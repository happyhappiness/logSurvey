			printf(" (from %s)",
			       find_unique_abbrev(parent->object.sha1,
						  abbrev_commit));
		show_decorations(opt, commit);
		printf("%s", diff_get_color_opt(&opt->diffopt, DIFF_RESET));
		if (opt->commit_format == CMIT_FMT_ONELINE) {
			putchar(' ');
		} else {
