	enum object_type type;

	if (!name)
		return 1;
	if (get_sha1(name, sha1) < 0)
		return 1;

	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		return 1;
	if (type != OBJ_BLOB)
		return 1;

	read_mailmap_buf(map, buf, size, repo_abbrev);

