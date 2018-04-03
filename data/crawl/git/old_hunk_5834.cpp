		strip_comments = 1;

	if (strbuf_read(&buf, 0, 1024) < 0)
		die("could not read the input");

	stripspace(&buf, strip_comments);

