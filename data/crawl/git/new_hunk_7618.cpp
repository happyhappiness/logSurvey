	if (fp == NULL)
		die("could not open %s", git_path(commit_editmsg));

	if (cleanup_mode != CLEANUP_NONE)
		stripspace(&sb, 0);

	if (signoff) {
		struct strbuf sob;
