		if (last_idnum < mark)
			last_idnum = mark;

		type = sha1_object_info(sha1, NULL);
		if (type < 0)
			die("object not found: %s", sha1_to_hex(sha1));

		if (type != OBJ_COMMIT)
			/* only commits */
			continue;

		object = parse_object(sha1);

		if (object->flags & SHOWN)
			error("Object %s already has a mark", sha1_to_hex(sha1));

		mark_object(object, mark);

		object->flags |= SHOWN;