{
	const char *from;
	struct branch *s;
	struct object_id oid;

	if (!skip_prefix(command_buf.buf, "from ", &from))
		return 0;

	oidcpy(&oid, &b->branch_tree.versions[1].oid);

	s = lookup_branch(from);
	if (b == s)
		die("Can't create a branch from itself: %s", b->name);
	else if (s) {
		struct object_id *t = &s->branch_tree.versions[1].oid;
		oidcpy(&b->oid, &s->oid);
		oidcpy(&b->branch_tree.versions[0].oid, t);
		oidcpy(&b->branch_tree.versions[1].oid, t);
	} else if (*from == ':') {
		uintmax_t idnum = parse_mark_ref_eol(from);
		struct object_entry *oe = find_mark(idnum);
