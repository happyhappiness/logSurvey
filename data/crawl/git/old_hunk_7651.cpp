	/* Start the fetch */
	cdata->got_alternates = 0;

	data = xmalloc(4096);
	buffer.size = 4096;
	buffer.posn = 0;
	buffer.buffer = data;

	if (walker->get_verbosely)
		fprintf(stderr, "Getting alternates list for %s\n", base);

