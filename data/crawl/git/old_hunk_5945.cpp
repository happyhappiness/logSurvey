				die("invalid %s", typename(type));
			if (fsck_object(obj, 1, fsck_error_function))
				die("Error in object");
			if (fsck_walk(obj, mark_link, 0))
				die("Not all child objects of %s are reachable", sha1_to_hex(obj->sha1));

			if (obj->type == OBJ_TREE) {
