	if (use_editor && include_status) {
		char *ai_tmp, *ci_tmp;
		if (in_merge)
			fprintf(s->fp,
				"#\n"
				"# It looks like you may be committing a MERGE.\n"
				"# If this is not correct, please remove the file\n"
				"#	%s\n"
				"# and try again.\n"
				"#\n",
				git_path("MERGE_HEAD"));

		fprintf(s->fp,
			"\n"
			"# Please enter the commit message for your changes.");
		if (cleanup_mode == CLEANUP_ALL)
			fprintf(s->fp,
				" Lines starting\n"
				"# with '#' will be ignored, and an empty"
				" message aborts the commit.\n");
		else /* CLEANUP_SPACE, that is. */
			fprintf(s->fp,
				" Lines starting\n"
				"# with '#' will be kept; you may remove them"
				" yourself if you want to.\n"
				"# An empty message aborts the commit.\n");
		if (only_include_assumed)
			fprintf(s->fp, "# %s\n", only_include_assumed);

		ai_tmp = cut_ident_timestamp_part(author_ident->buf);
		ci_tmp = cut_ident_timestamp_part(committer_ident.buf);
		if (strcmp(author_ident->buf, committer_ident.buf))
			fprintf(s->fp,
				"%s"
				"# Author:    %s\n",
				ident_shown++ ? "" : "#\n",
				author_ident->buf);

		if (!user_ident_sufficiently_given())
			fprintf(s->fp,
				"%s"
				"# Committer: %s\n",
				ident_shown++ ? "" : "#\n",
				committer_ident.buf);

		if (ident_shown)
			fprintf(s->fp, "#\n");

		saved_color_setting = s->use_color;
		s->use_color = 0;
