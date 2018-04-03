	mode_type = object_type(mode);
	if (mode_type != type_from_string(ptr)) {
		die("entry '%s' object type (%s) doesn't match mode type (%s)",
			path, ptr, typename(mode_type));
	}

	/* Check the type of object identified by sha1 */
