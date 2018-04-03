	struct commit_list *tried;
	int reaches = 0, all = 0, nr, steps;
	const unsigned char *bisect_rev;

	if (read_bisect_refs())
		die("reading bisect refs failed");
