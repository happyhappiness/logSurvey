	static const char *utf8 = "UTF-8";
	const char *use_encoding;
	char *encoding;
	const char *msg = get_commit_buffer(commit);
	char *out;

	if (!output_encoding || !*output_encoding) {
		if (commit_encoding)
			*commit_encoding =
