	struct object_info oi = {NULL};
	struct strbuf sb = STRBUF_INIT;
	unsigned flags = LOOKUP_REPLACE_OBJECT;

	if (unknown_type)
		flags |= LOOKUP_UNKNOWN_OBJECT;

	if (get_sha1_with_context(obj_name, 0, sha1, &obj_context))
		die("Not a valid object name %s", obj_name);

	buf = NULL;
	switch (opt) {
	case 't':
