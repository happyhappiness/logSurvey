
	strbuf_release(&sb);

	/* This checks and barfs if author is badly specified */
	determine_author_info(author_ident);

	/* This checks if committer ident is explicitly given */
	strbuf_addstr(&committer_ident, git_committer_info(0));
	if (use_editor && include_status) {
		char *ai_tmp, *ci_tmp;
		if (in_merge)
			fprintf(fp,
				"#\n"
