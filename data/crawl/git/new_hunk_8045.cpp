	if (has_pack_index(sha1))
		return 0;

	if (walker->get_verbosely)
		fprintf(stderr, "Getting index for pack %s\n", hex);

	url = xmalloc(strlen(repo->base) + 64);
