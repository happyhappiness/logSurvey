		if (last_idnum < mark)
			last_idnum = mark;

		object = parse_object(sha1);
		if (!object)
			continue;

		if (object->flags & SHOWN)
			error("Object %s already has a mark", sha1_to_hex(sha1));

		if (object->type != OBJ_COMMIT)
			/* only commits */
			continue;

		mark_object(object, mark);

		object->flags |= SHOWN;