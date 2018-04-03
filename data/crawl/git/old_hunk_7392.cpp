		if (get_sha1_hex(buffer+7, sha1) || buffer[47] != '\n')
			return objerror(&commit->object, "invalid 'parent' line format - bad sha1");
		buffer += 48;
	}
	if (memcmp(buffer, "author ", 7))
		return objerror(&commit->object, "invalid format - expected 'author' line");
