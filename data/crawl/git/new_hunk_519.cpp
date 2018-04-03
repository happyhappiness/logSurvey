			break;

		if (skip_prefix(line, "shallow ", &arg)) {
			struct object_id oid;
			struct object *object;
			if (get_oid_hex(arg, &oid))
				die("invalid shallow line: %s", line);
			object = parse_object(oid.hash);
			if (!object)
				continue;
			if (object->type != OBJ_COMMIT)
				die("invalid shallow object %s", oid_to_hex(&oid));
			if (!(object->flags & CLIENT_SHALLOW)) {
				object->flags |= CLIENT_SHALLOW;
				add_object_array(object, NULL, &shallows);
