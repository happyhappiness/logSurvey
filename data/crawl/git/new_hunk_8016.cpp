	if (quiet)
		transport->verbose = 0;
	if (upload_pack)
		set_option(TRANS_OPT_UPLOADPACK, upload_pack);
	if (keep)
		set_option(TRANS_OPT_KEEP, "yes");
	if (depth)
		set_option(TRANS_OPT_DEPTH, depth);

	if (!transport->url)
		die("Where do you want to fetch from today?");
