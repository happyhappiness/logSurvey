	int offset = 0;

	if (!buf)
		return error("Could not read object %s", sha1_to_hex(sha1));

	if (show_tag_object)
		while (offset < size && buf[offset] != '\n') {
