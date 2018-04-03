			printf(" (from %s)",
			       find_unique_abbrev(parent->object.sha1,
						  abbrev_commit));
		fputs(diff_get_color_opt(&opt->diffopt, DIFF_RESET), stdout);
		show_decorations(opt, commit);
		if (opt->commit_format == CMIT_FMT_ONELINE) {
			putchar(' ');
		} else {
