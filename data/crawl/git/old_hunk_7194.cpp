					   getenv("GIT_COMMITTER_EMAIL"));
		if (strcmp(author_ident, committer_ident))
			fprintf(fp,
				"#\n"
				"# Author:    %s\n"
				"#\n",
				author_ident);
		free(author_ident);

		saved_color_setting = wt_status_use_color;
		wt_status_use_color = 0;
		commitable = run_status(fp, index_file, prefix, 1);
