	unsigned long size;
	enum object_type type;
	int eaten;
	const unsigned char *repl;
	void *buffer = read_sha1_file_repl(sha1, &type, &size, &repl);

	if (buffer) {
		struct object *obj;
		if (check_sha1_signature(repl, buffer, size, typename(type)) < 0) {
			free(buffer);
			error("sha1 mismatch %s\n", sha1_to_hex(repl));
			return NULL;
		}

		obj = parse_object_buffer(repl, type, size, buffer, &eaten);
		if (!eaten)
			free(buffer);
		return obj;