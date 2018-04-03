		if (!get_sha1(arg, sha1)) {
			struct object *obj = lookup_object(sha1);

			/* Error is printed by lookup_object(). */
			if (!obj)
				continue;

			obj->used = 1;
			if (name_objects)
