	/* <commit-ish> */
	s = lookup_branch(p);
	if (s) {
		if (is_null_sha1(s->sha1))
			die("Can't add a note on empty branch.");
		hashcpy(commit_sha1, s->sha1);
	} else if (*p == ':') {
		uintmax_t commit_mark = parse_mark_ref_eol(p);
		struct object_entry *commit_oe = find_mark(commit_mark);
