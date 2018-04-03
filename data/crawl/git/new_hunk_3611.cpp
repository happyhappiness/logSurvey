			int recurse_limit)
{
	struct tree_desc one;
	void *one_buf = fill_tree_desc_strict(&one, hash1);

	while (one.size) {
		const char *path;