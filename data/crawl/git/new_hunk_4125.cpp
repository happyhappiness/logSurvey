	struct cache_entry *ce;
	unsigned mode;

	verify_working_tree_path(head_sha1, path);

	time(&now);
	commit = xcalloc(1, sizeof(*commit));
