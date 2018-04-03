	struct commit_list *tried;
	int reaches = 0, all = 0, nr, steps;
	const unsigned char *bisect_rev;
	char bisect_rev_hex[GIT_SHA1_HEXSZ + 1];

	if (read_bisect_refs())
		die("reading bisect refs failed");
