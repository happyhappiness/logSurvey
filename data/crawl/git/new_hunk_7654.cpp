		return error("Unable to start request");
	}

	strbuf_rtrim(&buffer);
	if (buffer.len != 40)
		return 1;
	return get_sha1_hex(buffer.buf, sha1);
}

static void cleanup(struct walker *walker)
