	if (s) {
		if (is_null_oid(&s->oid))
			die("Can't tag an empty branch.");
		hashcpy(sha1, s->oid.hash);
		type = OBJ_COMMIT;
	} else if (*from == ':') {
		struct object_entry *oe;
		from_mark = parse_mark_ref_eol(from);
		oe = find_mark(from_mark);
		type = oe->type;
		hashcpy(sha1, oe->idx.sha1);
	} else if (!get_sha1(from, sha1)) {
		struct object_entry *oe = find_object(sha1);
		if (!oe) {
			type = sha1_object_info(sha1, NULL);
			if (type < 0)
				die("Not a valid object: %s", from);
		} else
