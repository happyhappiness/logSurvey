	unsigned long uncompressed_size;
	unsigned long crc;
	unsigned long direntsize;
	unsigned long size;
	int method;
	int result = -1;
	int pathlen;
	unsigned char *out;
	char *path;
	enum object_type type;
	void *buffer = NULL;
	void *deflated = NULL;

	crc = crc32(0, NULL, 0);

	path = construct_path(base, baselen, filename, S_ISDIR(mode), &pathlen);
	if (is_archive_path_ignored(path + base_len))
		return 0;
	if (verbose)
		fprintf(stderr, "%s\n", path);
	if (pathlen > 0xffff) {
		error("path too long (%d chars, SHA1: %s): %s", pathlen,
		      sha1_to_hex(sha1), path);
		goto out;
	}

	if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
		method = 0;
		attr2 = 16;
		result = (S_ISDIR(mode) ? READ_TREE_RECURSIVE : 0);
		out = NULL;
		uncompressed_size = 0;
		compressed_size = 0;
