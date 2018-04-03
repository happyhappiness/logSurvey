	unsigned long size;
	enum object_type type;
	int eaten;
	void *buffer = read_sha1_file(sha1, &type, &size);

	if (buffer) {
		struct object *obj;
		if (check_sha1_signature(sha1, buffer, size, typename(type)) < 0) {
			free(buffer);
			error("sha1 mismatch %s\n", sha1_to_hex(sha1));
			return NULL;
		}

		obj = parse_object_buffer(sha1, type, size, buffer, &eaten);
		if (!eaten)
			free(buffer);
		return obj;