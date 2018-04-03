{
	struct commit *r = lookup_commit_reference(sha1);
	if (!r)
		die("Not a valid commit name %s", sha1_to_hex(sha1));
	return r;
}

