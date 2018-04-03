	strbuf_addstr(&committer_ident, git_committer_info(0));
	if (use_editor && include_status) {
		char *ai_tmp, *ci_tmp;
		if (whence != FROM_COMMIT)
			fprintf(fp,
				"#\n"
				"# It looks like you may be committing a %s.\n"
				"# If this is not correct, please remove the file\n"
				"#	%s\n"
				"# and try again.\n"
				"#\n",
				whence_s(),
				git_path(whence == FROM_MERGE
					 ? "MERGE_HEAD"
					 : "CHERRY_PICK_HEAD"));
		fprintf(fp,
			"\n"
			"# Please enter the commit message for your changes.");
