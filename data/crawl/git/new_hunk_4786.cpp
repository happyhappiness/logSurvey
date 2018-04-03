	if (use_editor && include_status) {
		char *ai_tmp, *ci_tmp;
		if (in_merge)
			status_printf_ln(s, GIT_COLOR_NORMAL,
				"\n"
				"It looks like you may be committing a MERGE.\n"
				"If this is not correct, please remove the file\n"
				"	%s\n"
				"and try again.\n"
				"",
				git_path("MERGE_HEAD"));

		fprintf(s->fp, "\n");
		status_printf(s, GIT_COLOR_NORMAL,
			"Please enter the commit message for your changes.");
		if (cleanup_mode == CLEANUP_ALL)
			status_printf_more(s, GIT_COLOR_NORMAL,
				" Lines starting\n"
				"with '#' will be ignored, and an empty"
				" message aborts the commit.\n");
		else /* CLEANUP_SPACE, that is. */
			status_printf_more(s, GIT_COLOR_NORMAL,
				" Lines starting\n"
				"with '#' will be kept; you may remove them"
				" yourself if you want to.\n"
				"An empty message aborts the commit.\n");
		if (only_include_assumed)
			status_printf_ln(s, GIT_COLOR_NORMAL,
					"%s", only_include_assumed);

		ai_tmp = cut_ident_timestamp_part(author_ident->buf);
		ci_tmp = cut_ident_timestamp_part(committer_ident.buf);
		if (strcmp(author_ident->buf, committer_ident.buf))
			status_printf_ln(s, GIT_COLOR_NORMAL,
				"%s"
				"Author:    %s",
				ident_shown++ ? "" : "\n",
				author_ident->buf);

		if (!user_ident_sufficiently_given())
			status_printf_ln(s, GIT_COLOR_NORMAL,
				"%s"
				"Committer: %s",
				ident_shown++ ? "" : "\n",
				committer_ident.buf);

		if (ident_shown)
			status_printf_ln(s, GIT_COLOR_NORMAL, "");

		saved_color_setting = s->use_color;
		s->use_color = 0;
