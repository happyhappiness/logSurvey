{
	const char *from;
	struct branch *s;
	unsigned char sha1[20];

	if (!skip_prefix(command_buf.buf, "from ", &from))
		return 0;

	hashcpy(sha1, b->branch_tree.versions[1].oid.hash);

	s = lookup_branch(from);
	if (b == s)
		die("Can't create a branch from itself: %s", b->name);
	else if (s) {
		unsigned char *t = s->branch_tree.versions[1].oid.hash;
		oidcpy(&b->oid, &s->oid);
		hashcpy(b->branch_tree.versions[0].oid.hash, t);
		hashcpy(b->branch_tree.versions[1].oid.hash, t);
	} else if (*from == ':') {
		uintmax_t idnum = parse_mark_ref_eol(from);
		struct object_entry *oe = find_mark(idnum);
