{
	static struct cache_entry *dfc;

	if (len > MAX_UNPACK_TREES)
		die("unpack_trees takes at most %d trees", MAX_UNPACK_TREES);
	memset(&state, 0, sizeof(state));
	state.base_dir = "";
	state.force = 1;
