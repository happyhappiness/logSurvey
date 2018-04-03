	struct commit *commit = NULL;

	if (rev->commit_format != CMIT_FMT_EMAIL)
		die("Cover letter needs email format");

	committer = git_committer_info(0);

