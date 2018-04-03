	if (s) {
		if (is_null_oid(&s->oid))
			die("Can't tag an empty branch.");
		oidcpy(&oid, &s->oid);
		type = OBJ_COMMIT;
	} else if (*from == ':') {
		struct object_entry *oe;
		from_mark = parse_mark_ref_eol(from);
		oe = find_mark(from_mark);
		type = oe->type;
		hashcpy(oid.hash, oe->idx.sha1);
	} else if (!get_oid(from, &oid)) {
		struct object_entry *oe = find_object(&oid);
		if (!oe) {
			type = sha1_object_info(oid.hash, NULL);
			if (type < 0)
				die("Not a valid object: %s", from);
		} else
