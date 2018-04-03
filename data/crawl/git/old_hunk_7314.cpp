{
	static struct cache_entry *dfc;

	if (len > 4)
		die("unpack_trees takes at most four trees");
	memset(&state, 0, sizeof(state));
	state.base_dir = "";
	state.force = 1;
