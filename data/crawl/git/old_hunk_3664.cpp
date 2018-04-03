			/* only commits */
			continue;

		object = parse_object(sha1);

		if (object->flags & SHOWN)
			error("Object %s already has a mark", sha1_to_hex(sha1));