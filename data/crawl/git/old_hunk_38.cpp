			obj_type = sha1_object_info(object.hash, NULL);
			repl_type = sha1_object_info(oid->hash, NULL);

			printf("%s (%s) -> %s (%s)\n", refname, typename(obj_type),
			       oid_to_hex(oid), typename(repl_type));
		}
	}

