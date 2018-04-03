	if (!buf)
		return error("Could not read object %s", sha1_to_hex(sha1));

	if (show_tag_object)
		while (offset < size && buf[offset] != '\n') {
			int new_offset = offset + 1;
			while (new_offset < size && buf[new_offset++] != '\n')
				; /* do nothing */
			if (!prefixcmp(buf + offset, "tagger "))
				show_tagger(buf + offset + 7,
					    new_offset - offset - 7, rev);
			offset = new_offset;
		}

