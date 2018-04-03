		if (only_include_assumed)
			fprintf(fp, "# %s\n", only_include_assumed);

		ai_tmp = cut_ident_timestamp_part(author_ident->buf);
		ci_tmp = cut_ident_timestamp_part(committer_ident.buf);
		if (strcmp(author_ident->buf, committer_ident.buf))
			fprintf(fp,
				"%s"
				"# Author:    %s\n",
				ident_shown++ ? "" : "#\n",
				author_ident->buf);

		if (!user_ident_sufficiently_given())
			fprintf(fp,
				"%s"
				"# Committer: %s\n",
				ident_shown++ ? "" : "#\n",
				committer_ident.buf);

		if (ident_shown)
			fprintf(fp, "#\n");
