	int err = 0;
	struct idx_entry *entries;

	if (!is_pack_valid(p))
		return error("packfile %s cannot be accessed", p->pack_name);

	git_SHA1_Init(&ctx);
	do {