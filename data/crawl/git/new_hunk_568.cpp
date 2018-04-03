		*end = 0;
		mark = strtoumax(line + 1, &end, 10);
		if (!mark || end == line + 1
			|| *end != ' ' || get_oid_hex(end + 1, &oid))
			die("corrupt mark line: %s", line);
		e = find_object(&oid);
		if (!e) {
			enum object_type type = sha1_object_info(oid.hash, NULL);
			if (type < 0)
				die("object not found: %s", oid_to_hex(&oid));
			e = insert_object(&oid);
			e->type = type;
			e->pack_id = MAX_PACK_ID;
			e->idx.offset = 1; /* just not zero! */
