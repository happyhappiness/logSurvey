		if (data->format == REPLACE_FORMAT_SHORT)
			printf("%s\n", refname);
		else if (data->format == REPLACE_FORMAT_MEDIUM)
			printf("%s -> %s\n", refname, sha1_to_hex(sha1));
		else { /* data->format == REPLACE_FORMAT_LONG */
			unsigned char object[20];
			enum object_type obj_type, repl_type;

			if (get_sha1(refname, object))
				return error("Failed to resolve '%s' as a valid ref.", refname);

			obj_type = sha1_object_info(object, NULL);
			repl_type = sha1_object_info(sha1, NULL);

			printf("%s (%s) -> %s (%s)\n", refname, typename(obj_type),
			       sha1_to_hex(sha1), typename(repl_type));
		}
	}

