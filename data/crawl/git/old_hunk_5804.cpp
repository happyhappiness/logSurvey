	char *buf;
	const char *tagger, *tagger_end, *message;
	size_t message_size = 0;

	buf = read_sha1_file(tag->object.sha1, &type, &size);
	if (!buf)
