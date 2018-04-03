	enum object_type type;
	char *buf;
	struct object *object;

	if (no_data)
		return;

	if (is_null_sha1(sha1))
		return;

	object = parse_object(sha1);
	if (!object)
		die ("Could not read blob %s", sha1_to_hex(sha1));

	if (object->flags & SHOWN)
		return;

	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		die ("Could not read blob %s", sha1_to_hex(sha1));

	mark_next_object(object);

