	if (!buf)
		return error("Could not read object %s", sha1_to_hex(sha1));

	if (suppress_header)
		while (offset < size && buf[offset++] != '\n') {
			int new_offset = offset;
			while (new_offset < size && buf[new_offset++] != '\n')
				; /* do nothing */
			offset = new_offset;
		}

