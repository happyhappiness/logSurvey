	if (slurp_attr(line->buf, "boundary=", boundary)) {
		strbuf_insert(boundary, 0, "--", 2);
		if (++mi->content_top >= &mi->content[MAX_BOUNDARIES]) {
			fprintf(stderr, "Too many boundaries to handle\n");
			exit(1);
		}
		*(mi->content_top) = boundary;
		boundary = NULL;
