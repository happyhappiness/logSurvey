
	if (get_oid(rev, &oid))
		die("unknown rev %s", rev);
	buf = fill_tree_descriptor(desc, &oid);
	if (!buf)
		die("%s is not a tree", rev);
	return buf;
