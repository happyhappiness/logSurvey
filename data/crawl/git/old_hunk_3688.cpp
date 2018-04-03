				die("invalid shallow line: %s", line);
			object = parse_object(sha1);
			if (!object)
				die("did not find object for %s", line);
			if (object->type != OBJ_COMMIT)
				die("invalid shallow object %s", sha1_to_hex(sha1));
			if (!(object->flags & CLIENT_SHALLOW)) {