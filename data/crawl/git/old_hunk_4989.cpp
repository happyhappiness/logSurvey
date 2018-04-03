	else if (in_merge)
		hook_arg1 = "merge";

	fp = fopen(git_path(commit_editmsg), "w");
	if (fp == NULL)
		die_errno("could not open '%s'", git_path(commit_editmsg));
