	static const char *utf8 = "UTF-8";
	const char *use_encoding;
	char *encoding;
	char *msg = commit->buffer;
	char *out;

	if (!msg) {
		enum object_type type;
		unsigned long size;

		msg = read_sha1_file(commit->object.sha1, &type, &size);
		if (!msg)
			die("Cannot read commit object %s",
			    sha1_to_hex(commit->object.sha1));
		if (type != OBJ_COMMIT)
			die("Expected commit for '%s', got %s",
			    sha1_to_hex(commit->object.sha1), typename(type));
	}

	if (!output_encoding || !*output_encoding) {
		if (commit_encoding)
			*commit_encoding =
