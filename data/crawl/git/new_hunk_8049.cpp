	buffer.posn = 0;
	buffer.buffer = data;

	if (walker->get_verbosely)
		fprintf(stderr, "Getting pack list for %s\n", repo->base);

	url = xmalloc(strlen(repo->base) + 21);
