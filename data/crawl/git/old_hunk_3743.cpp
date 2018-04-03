			|| *mark_end != ' ' || get_sha1(mark_end + 1, sha1))
			die("corrupt mark line: %s", line);

		object = parse_object(sha1);
		if (!object)
			die ("Could not read blob %s", sha1_to_hex(sha1));

		if (object->flags & SHOWN)
			error("Object %s already has a mark", sha1_to_hex(sha1));
