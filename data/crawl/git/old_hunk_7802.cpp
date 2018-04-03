			       diff_unique_abbrev(parent->object.sha1,
						  abbrev_commit));
		show_decorations(commit);
		printf("%s",
		       diff_get_color(opt->diffopt.color_diff, DIFF_RESET));
		putchar(opt->commit_format == CMIT_FMT_ONELINE ? ' ' : '\n');
		if (opt->reflog_info) {
			show_reflog_message(opt->reflog_info,
