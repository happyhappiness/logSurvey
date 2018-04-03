	if (options.depth)
		die("dumb http transport does not support --depth");
	for (i = 0; i < nr_heads; i++)
		targets[i] = xstrdup(sha1_to_hex(to_fetch[i]->old_sha1));

	walker = get_http_walker(url.buf);
	walker->get_all = 1;