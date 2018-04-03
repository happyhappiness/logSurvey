	int cnt = 0;
	struct rev_info rev;

	if (read_cache() < 0)
		die("failed to read the cache");

