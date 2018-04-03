	if (!p->index_data && open_pack_index(p))
		return error("packfile %s index unavailable", p->pack_name);

	p->pack_fd = git_open_noatime(p->pack_name, p);
	if (p->pack_fd < 0 || fstat(p->pack_fd, &st))
		return -1;

	/* If we created the struct before we had the pack we lack size. */
	if (!p->pack_size) {
