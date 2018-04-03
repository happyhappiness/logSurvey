			die("invalid quoting");
		path = strbuf_detach(&p_uq, NULL);
	}

	/*
	 * Object type is redundantly derivable three ways.
	 * These should all agree.
	 */
	mode_type = object_type(mode);
	if (mode_type != type_from_string(ptr)) {
		die("entry '%s' object type (%s) doesn't match mode type (%s)",
			path, ptr, typename(mode_type));
	}

	/* Check the type of object identified by sha1 */
	obj_type = sha1_object_info(sha1, NULL);
	if (obj_type < 0) {
		if (allow_missing) {
			; /* no problem - missing objects are presumed to be of the right type */
		} else {
			die("entry '%s' object %s is unavailable", path, sha1_to_hex(sha1));
		}
	} else {
		if (obj_type != mode_type) {
			/*
			 * The object exists but is of the wrong type.
			 * This is a problem regardless of allow_missing
			 * because the new tree entry will never be correct.
			 */
			die("entry '%s' object %s is a %s but specified type was (%s)",
				path, sha1_to_hex(sha1), typename(obj_type), typename(mode_type));
		}
	}

	append_to_tree(mode, sha1, path);
}
