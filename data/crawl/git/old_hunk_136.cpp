	if (*subpath)
		subpath++;

	buf = read_sha1_file(hash1, &type, &sz);
	if (!buf)
		die("cannot read tree %s", sha1_to_hex(hash1));
	init_tree_desc(&desc, buf, sz);

	rewrite_here = NULL;
