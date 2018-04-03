					   getenv("GIT_COMMITTER_EMAIL"));
		if (strcmp(author_ident, committer_ident))
			fprintf(fp,
				"%s"
				"# Author:    %s\n",
				ident_shown++ ? "" : "#\n",
				author_ident);
		free(author_ident);

		if (!user_ident_explicitly_given)
			fprintf(fp,
				"%s"
				"# Committer: %s\n",
				ident_shown++ ? "" : "#\n",
				committer_ident);

		if (ident_shown)
			fprintf(fp, "#\n");

		saved_color_setting = wt_status_use_color;
		wt_status_use_color = 0;
		commitable = run_status(fp, index_file, prefix, 1);
