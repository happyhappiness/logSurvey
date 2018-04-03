	struct strbuf msg = STRBUF_INIT;
	const char *old_desc;
	if (opts->new_branch) {
		if (!opts->new_orphan_branch)
			create_branch(old->name, opts->new_branch, new->name, 0,
				      opts->new_branch_log, opts->track);
		new->name = opts->new_branch;
