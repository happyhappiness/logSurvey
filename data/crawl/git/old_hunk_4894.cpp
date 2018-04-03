		if (only_include_assumed)
			fprintf(fp, "# %s\n", only_include_assumed);

		author_ident = xstrdup(fmt_name(author_name, author_email));
		committer_ident = fmt_name(getenv("GIT_COMMITTER_NAME"),
					   getenv("GIT_COMMITTER_EMAIL"));
		if (strcmp(author_ident, committer_ident))
			fprintf(fp,
				"%s"
				"# Author:    %s\n",
				ident_shown++ ? "" : "#\n",
				author_ident);
		free(author_ident);

		if (!user_ident_sufficiently_given())
			fprintf(fp,
				"%s"
				"# Committer: %s\n",
				ident_shown++ ? "" : "#\n",
				committer_ident);

		if (ident_shown)
			fprintf(fp, "#\n");
