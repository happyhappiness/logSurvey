
	fp = fopen(git_path(commit_editmsg), "w");
	if (fp == NULL)
		die("could not open %s: %s",
		    git_path(commit_editmsg), strerror(errno));

	if (cleanup_mode != CLEANUP_NONE)
		stripspace(&sb, 0);