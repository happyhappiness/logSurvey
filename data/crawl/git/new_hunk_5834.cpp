		strip_comments = 1;

	if (strbuf_read(&buf, 0, 1024) < 0)
		die_errno("could not read the input");

	stripspace(&buf, strip_comments);

