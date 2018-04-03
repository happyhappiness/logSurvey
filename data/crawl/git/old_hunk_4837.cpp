	strbuf_addstr(&committer_ident, git_committer_info(0));
	if (use_editor && include_status) {
		char *ai_tmp, *ci_tmp;
		if (in_merge)
			fprintf(fp,
				"#\n"
				"# It looks like you may be committing a MERGE.\n"
				"# If this is not correct, please remove the file\n"
				"#	%s\n"
				"# and try again.\n"
				"#\n",
				git_path("MERGE_HEAD"));

		fprintf(fp,
			"\n"
			"# Please enter the commit message for your changes.");
