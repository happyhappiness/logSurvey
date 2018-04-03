						  abbrev_commit));
		show_decorations(commit);
		printf("%s", diff_get_color_opt(&opt->diffopt, DIFF_RESET));
		if (opt->commit_format == CMIT_FMT_ONELINE) {
			putchar(' ');
		} else {
			putchar('\n');
			graph_show_oneline(opt->graph);
		}
		if (opt->reflog_info) {
			/*
			 * setup_revisions() ensures that opt->reflog_info
			 * and opt->graph cannot both be set,
			 * so we don't need to worry about printing the
			 * graph info here.
			 */
			show_reflog_message(opt->reflog_info,
				    opt->commit_format == CMIT_FMT_ONELINE,
				    opt->date_mode);
