	unsigned long uncompressed_size;
	unsigned long crc;
	unsigned long direntsize;
	int method;
	unsigned char *out;
	void *deflated = NULL;

	crc = crc32(0, NULL, 0);

	if (pathlen > 0xffff) {
		return error("path too long (%d chars, SHA1: %s): %s",
				(int)pathlen, sha1_to_hex(sha1), path);
	}

	if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
		method = 0;
		attr2 = 16;
		out = NULL;
		uncompressed_size = 0;
		compressed_size = 0;
