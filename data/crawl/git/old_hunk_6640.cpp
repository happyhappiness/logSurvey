			printf(" (from %s)",
			       diff_unique_abbrev(parent->object.sha1,
						  abbrev_commit));
		show_decorations(commit);
		printf("%s", diff_get_color_opt(&opt->diffopt, DIFF_RESET));
		if (opt->commit_format == CMIT_FMT_ONELINE) {
			putchar(' ');
