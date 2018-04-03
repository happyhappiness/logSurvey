
	strbuf_release(&sb);

	determine_author_info();

	/* This checks if committer ident is explicitly given */
	git_committer_info(0);
	if (use_editor && include_status) {
		char *author_ident;
		const char *committer_ident;

		if (in_merge)
			fprintf(fp,
				"#\n"
