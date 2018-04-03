		*end = 0;
		mark = strtoumax(line + 1, &end, 10);
		if (!mark || end == line + 1
			|| *end != ' ' || get_sha1_hex(end + 1, sha1))
			die("corrupt mark line: %s", line);
		e = find_object(sha1);
		if (!e) {
			enum object_type type = sha1_object_info(sha1, NULL);
			if (type < 0)
				die("object not found: %s", sha1_to_hex(sha1));
			e = insert_object(sha1);
			e->type = type;
			e->pack_id = MAX_PACK_ID;
			e->idx.offset = 1; /* just not zero! */
