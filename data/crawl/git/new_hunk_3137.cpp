	unsigned char orig_head[GIT_SHA1_RAWSZ], curr_head[GIT_SHA1_RAWSZ];
	unsigned char rebase_fork_point[GIT_SHA1_RAWSZ];

	if (!getenv("GIT_REFLOG_ACTION"))
		set_reflog_message(argc, argv);
