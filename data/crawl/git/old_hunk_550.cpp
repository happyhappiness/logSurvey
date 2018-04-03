		e = find_mark(parse_mark_ref_space(p));
		if (!e)
			die("Unknown mark: %s", command_buf.buf);
		hashcpy(oid.hash, e->idx.sha1);
	} else {	/* <sha1> */
		if (parse_oid_hex(*p, &oid, p))
			die("Invalid dataref: %s", command_buf.buf);
