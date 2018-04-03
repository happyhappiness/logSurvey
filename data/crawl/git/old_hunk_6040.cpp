	const unsigned char *bisect_rev;
	char bisect_rev_hex[41];

	bisect_common(&revs, prefix, &reaches, &all);

	revs.commits = filter_skipped(revs.commits, &tried, 0);
