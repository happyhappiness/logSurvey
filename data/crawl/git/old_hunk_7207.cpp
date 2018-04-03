						  abbrev_commit));
		show_decorations(commit);
		printf("%s", diff_get_color_opt(&opt->diffopt, DIFF_RESET));
		putchar(opt->commit_format == CMIT_FMT_ONELINE ? ' ' : '\n');
		if (opt->reflog_info) {
			show_reflog_message(opt->reflog_info,
				    opt->commit_format == CMIT_FMT_ONELINE,
				    opt->date_mode);
