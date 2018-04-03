		if (!get_sha1(arg, sha1)) {
			struct object *obj = lookup_object(sha1);

			if (!obj) {
				error("%s: object missing", sha1_to_hex(sha1));
				errors_found |= ERROR_OBJECT;
				continue;
			}

			obj->used = 1;
			if (name_objects)
