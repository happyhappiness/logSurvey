{
	memset(ids, 0, sizeof(*ids));
	diff_setup(&ids->diffopts);
	ids->diffopts.recursive = 1;
	if (diff_setup_done(&ids->diffopts) < 0)
		return error("diff_setup_done failed");
	return 0;